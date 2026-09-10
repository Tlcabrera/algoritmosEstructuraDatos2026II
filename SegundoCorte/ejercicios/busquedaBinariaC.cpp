#include <vector>
using namespace std;

// Retorna un índice i con a[i]==x, o -1.
// Precondición: a ordenado de forma no decreciente.
int busquedaBinaria(const vector<int>& a, int x) {
    int lo = 0, hi = (int)a.size() - 1;   // rango CERRADO [lo, hi]

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;     // evita desbordamiento
        if      (a[mid] == x) return mid;
        else if (a[mid] <  x) lo = mid + 1;   // descarta mitad izquierda
        else                  hi = mid - 1;   // descarta mitad derecha
    }
    return -1;                            // rango vacío ⇒ no está
}
//recursiva

int binariaRec(const vector<int>& a, int x, int lo, int hi) {
    if (lo > hi) return -1;                          // caso base: vacío
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == x) return mid;                     // caso base: hallado
    if (a[mid] <  x) return binariaRec(a, x, mid + 1, hi);
    else             return binariaRec(a, x, lo, mid - 1);
}
// Llamada: binariaRec(a, x, 0, (int)a.size() - 1);