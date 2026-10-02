#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <typename T>
class Cola {
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& d) : dato(d), siguiente(nullptr) {}
    };
    Nodo* frente = nullptr;   // por aquí se SALE
    Nodo* fin = nullptr;      // por aquí se ENTRA
    int n = 0;
 
public:
    Cola() = default;
    ~Cola() {                                 // liberar TODOS los nodos
        while (frente != nullptr) {
            Nodo* tmp = frente;
            frente = frente->siguiente;
            delete tmp;
        }
    }
    Cola(const Cola&) = delete;               // evita copias superficiales (doble delete)
    Cola& operator=(const Cola&) = delete;
 
    void encolar(const T& x) {                // O(1)
        Nodo* nuevo = new Nodo(x);
        if (fin == nullptr) {                 // cola vacía
            frente = fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        n++;
    }
 
    bool desencolar(T& x) {                   // O(1); false si está vacía
        if (frente == nullptr) return false;
        Nodo* viejo = frente;
        x = viejo->dato;
        frente = frente->siguiente;
        if (frente == nullptr) fin = nullptr; // <- EL CASO QUE SE OLVIDA
        delete viejo;                         // en C++, sin esto hay fuga de memoria
        n--;
        return true;
        // Si se olvida la línea marcada, 'fin' queda apuntando a memoria
        // LIBERADA (puntero colgante): el siguiente encolar escribe en basura.
        // En Python el dato "desaparece"; en C++ es comportamiento indefinido.
    }
 
    bool verFrente(T& x) const {
        if (frente == nullptr) return false;
        x = frente->dato;
        return true;
    }
    bool vacia() const { return n == 0; }
    int tamano() const { return n; }
};
template <typename T>
class ColaCircular {
    T* datos;
    int cap;
    int frente = 0;
    int n = 0;
 
public:
    explicit ColaCircular(int c) : datos(new T[c]), cap(c) {}
    ~ColaCircular() { delete[] datos; }       // new[] se libera con delete[]
    ColaCircular(const ColaCircular&) = delete;
    ColaCircular& operator=(const ColaCircular&) = delete;
 
    bool encolar(const T& x) {                // O(1)
        if (n == cap) return false;           // llena: no crece
        datos[(frente + n) % cap] = x;        // el módulo da la vuelta
        n++;
        return true;
    }
 
    bool desencolar(T& x) {                   // O(1)
        if (n == 0) return false;
        x = datos[frente];
        frente = (frente + 1) % cap;
        n--;
        return true;
    }
 
    bool vacia() const { return n == 0; }
    bool lleno() const { return n == cap; }
    int posFrente() const { return frente; }
 
    void imprimirInterno() const {            // el arreglo tal como está en memoria
        cout << "[";
        for (int i = 0; i < cap; i++) cout << (i ? ", " : "") << "'" << datos[i] << "'";
        cout << "]";
    }
    void imprimirLogico() const {             // como la "ve" la cola
        cout << "[";
        for (int i = 0; i < n; i++) cout << (i ? ", " : "") << "'" << datos[(frente + i) % cap] << "'";
        cout << "]";
    }
};
 
// Utilidad: desencolar y mostrar "None" si estaba vacía (igual que Python)
template <typename C>
string sacar(C& c) {
    string x;
    return c.desencolar(x) ? x : "None";
}
 //Algoritmo sala de espera con 3 sillas