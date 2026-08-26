#include <iostream>
using namespace std;
 
int main() {
    const int N = 8;
    int lecturas[N] = {23, 7, 91, 45, 7, 60, 12, 88};
 
    int  maximo = lecturas[0];   // se parte del primer elemento,
    int  minimo = lecturas[0];   // NUNCA de 0 ni de un numero inventado
    long suma   = 0;
 
    for (int i = 0; i < N; i++) {
        if (lecturas[i] > maximo) maximo = lecturas[i];
        if (lecturas[i] < minimo) minimo = lecturas[i];
        suma += lecturas[i];
    }
 
    double promedio = (double)suma / N;   // el cast evita division entera
 
    cout << "Maximo:   " << maximo   << endl;
    cout << "Minimo:   " << minimo   << endl;
    cout << "Promedio: " << promedio << endl;
    return 0;
}
