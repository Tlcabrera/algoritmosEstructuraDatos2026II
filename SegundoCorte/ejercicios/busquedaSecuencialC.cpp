#include <vector>
using namespace std;

// Retorna el índice de la primera aparición de x, o -1.
// Sin precondiciones: el arreglo puede estar desordenado.
int busquedaSecuencial(const vector<int>& a, int x) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == x) return i;      // encontrado
    }
    return -1;                        // recorrido completo sin éxito
}

//version recursiva
int secuencialRec(const vector<int>& a, int x, int i = 0) {
    if (i >= (int)a.size()) return -1;          // caso base: agotado
    if (a[i] == x)          return i;           // caso base: encontrado
    return secuencialRec(a, x, i + 1);          // paso recursivo
}