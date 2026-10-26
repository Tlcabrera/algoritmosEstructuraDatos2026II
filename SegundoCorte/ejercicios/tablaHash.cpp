#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <chrono>
#include <cstdio>
using namespace std;

class TablaHash {
private:
    int cap;
    vector<list<pair<string, string>>> cubetas;   // encadenamiento
    int n;

    int hashear(const string& clave) const {
        unsigned long long h = 0;
        for (unsigned char c : clave) {
            h = (h * 31 + c) % cap;               // 31: primo, dispersa bien
        }
        return (int)h;
    }

public:
    TablaHash(int capacidad = 8) : cap(capacidad), cubetas(capacidad), n(0) {}

    void insertar(const string& clave, const string& valor) {
        int i = hashear(clave);
        for (auto& par : cubetas[i]) {
            if (par.first == clave) {
                par.second = valor;               // ACTUALIZA, no duplica
                return;
            }
        }
        cubetas[i].push_back({clave, valor});
        n++;
    }

    // Devuelve true si la encontro y deja el valor en 'salida'
    bool buscar(const string& clave, string& salida) const {
        int i = hashear(clave);
        for (const auto& par : cubetas[i]) {      // recorre SOLO esa cubeta
            if (par.first == clave) {
                salida = par.second;
                return true;
            }
        }
        return false;
    }

    bool eliminar(const string& clave) {
        int i = hashear(clave);
        for (auto it = cubetas[i].begin(); it != cubetas[i].end(); ++it) {
            if (it->first == clave) {
                cubetas[i].erase(it);
                n--;
                return true;
            }
        }
        return false;
    }

    vector<int> distribucion() const {
        vector<int> d;
        for (const auto& c : cubetas) d.push_back((int)c.size());
        return d;
    }

    double factorCarga() const { return (double)n / cap; }
    int tamano() const { return n; }
};

void imprimir(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    // ---------- Demostracion ----------
    vector<string> codigos = {"REC-001", "REC-002", "REC-003", "EQ-100",
                              "EQ-101", "PA-007", "PA-008", "EST-42"};
    TablaHash t(8);
    for (const auto& c : codigos) t.insertar(c, "valor de " + c);

    string v;
    cout << "distribucion por cubeta: "; imprimir(t.distribucion());
    printf("factor de carga        : %.1f\n", t.factorCarga());
    cout << "buscar REC-002         : " << (t.buscar("REC-002", v) ? v : "None") << endl;
    cout << "buscar NO-EXISTE       : " << (t.buscar("NO-EXISTE", v) ? v : "None") << endl;
    t.insertar("REC-002", "valor NUEVO");
    t.buscar("REC-002", v);
    cout << "actualizar REC-002     : " << v << " | n = " << t.tamano() << endl;
    cout << "eliminar EQ-100        : " << (t.eliminar("EQ-100") ? "True" : "False") << endl;
    cout << "distribucion despues   : "; imprimir(t.distribucion());
    int colisiones = 0;
    for (int x : t.distribucion()) if (x > 1) colisiones++;
    cout << "colisiones (cubetas con mas de un elemento): " << colisiones << endl;

    // ---------- Medicion: lista vs tabla hash ----------
    const int N = 20000, B = 200;
    vector<pair<string, int>> lista;
    TablaHash tabla(32768);
    char buf[16];
    for (int i = 0; i < N; i++) {
        snprintf(buf, sizeof(buf), "COD-%05d", i);
        lista.push_back({buf, i});
        tabla.insertar(buf, to_string(i));
    }
    snprintf(buf, sizeof(buf), "COD-%05d", N - 1);  // el ULTIMO: peor caso
    string objetivo = buf;

    volatile int encontrados = 0;
    auto t0 = chrono::steady_clock::now();
    for (int b = 0; b < B; b++) {
        for (const auto& p : lista) {
            if (p.first == objetivo) { encontrados++; break; }
        }
    }
    double tLista = chrono::duration<double>(chrono::steady_clock::now() - t0).count();

    t0 = chrono::steady_clock::now();
    for (int b = 0; b < B; b++) {
        if (tabla.buscar(objetivo, v)) encontrados++;
    }
    double tTabla = chrono::duration<double>(chrono::steady_clock::now() - t0).count();

    printf("\n%d busquedas sobre %d elementos:\n", B, N);
    printf("  lista (recorre) : %.5f s\n", tLista);
    printf("  tabla hash      : %.5f s\n", tTabla);
    printf("  la tabla fue ~%.0f veces mas rapida\n", tLista / tTabla);
    return 0;
}