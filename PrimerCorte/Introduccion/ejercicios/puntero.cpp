/*int x = 10;
 
int* p = &x;   // '*' en la DECLARACION: p es un puntero a int
               // '&' delante de x: dame la DIRECCION de x
 
cout << p;     // imprime la direccion (algo como 0x7ffd08a805b8)
cout << *p;    // '*' en el USO: dame el VALOR apuntado -> 10
cout << x;
x=99;
*p = 99;       // modifica x a traves de p
cout << x;     // 99
*/

// Intercambiar el valor de dos variables usando punteros
#include <iostream>
using namespace std;
void porValor(int a, int b) {
    int t = a;
    a = b;
    b = t;
}
void porPuntero(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void porReferencia(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}
int main() {
    int x = 10, y = 20;
    cout << "Antes de porValor: x=" << x << ", y=" << y << endl;
    porValor(x, y);

    cout << "Despues de porValor: x=" << x << ", y=" << y << endl;

    cout << "Antes de porPuntero: x=" << x << ", y=" << y << endl;
    porPuntero(&x, &y);
    cout << "Despues de porPuntero: x=" << x << ", y=" << y << endl;

    cout << "Antes de porReferencia: x=" << x << ", y=" << y << endl;
    porReferencia(x, y);
    cout << "Despues de porReferencia: x=" << x << ", y=" << y << endl;
    cout << "x vive en la direccion: " << &x << endl;
    return 0;
}