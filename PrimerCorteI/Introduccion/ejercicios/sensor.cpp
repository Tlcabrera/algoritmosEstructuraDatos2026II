#include <iostream>


int main() {
    const int TAM = 6;
    int lecturas[TAM];

    std::cout << "Ingrese las " << TAM << " lecturas del sensor (use -999 para indicar un dato danado):" << std::endl;
    for (int i = 0; i < TAM; i++) {
        std::cout << "Lectura " << (i + 1) << ": ";
        std::cin >> lecturas[i];
    }

    int suma = 0;
    int validos = 0;
    int descartados = 0;

    for (int i = 0; i < TAM; i++) {
        if (lecturas[i] == -999) {
            descartados++;
        } else {
            suma += lecturas[i];
            validos++;
        }
    }

    double promedio = 0.0;
    if (validos > 0) {
        promedio = static_cast<double>(suma) / validos;
    }

    std::cout << std::endl;
    std::cout << "Lecturas validas: " << validos << std::endl;
    std::cout << "Lecturas descartadas: " << descartados << std::endl;
    std::cout << "Promedio real: " << promedio << std::endl;

    return 0;
}