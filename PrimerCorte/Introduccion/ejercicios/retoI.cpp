#include <iostream>
using namespace std;

int main() {
   const int N = 6;
    int lecturas[N] = {20, -999, 22, 24, -999, 26};

    int suma = 0;
    int validos = 0;
    int descartados = 0;

    for (int i = 0; i < N; i++) {
        if (lecturas[i] != -999) {
            suma += lecturas[i];
            validos++;
        } else {
            descartados++;
        }
    }
    double promedio=0.0;
    if (validos > 0) {
        promedio = (double)suma / validos;
    }
    std::cout<<"Lecturas validas: "<<validos<<endl;
    std::cout<<"Lecturas descartadas: "<<descartados<<endl;
    std::cout<<"Promedio: "<<promedio<<endl;

    return 0;

}