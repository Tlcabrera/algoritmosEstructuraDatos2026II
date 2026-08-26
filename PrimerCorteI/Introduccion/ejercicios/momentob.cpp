#include <iostream>
using namespace std;

int main() {
    int cantidad;
    cout << "¿Cuantos puntos de acopio nuevos va a registrar? ";
    cin >> cantidad;

    //Validación de la cantidad de puntos de acopio
    if (cantidad <= 0) {
        cout << "La cantidad de puntos de acopio debe ser mayor a cero." << endl;
        return 1; // Salir del programa con un código de error
    }
    //reservar memoria para la cantidad de puntos de acopio dinámicamente
    double* pesos = new double[cantidad];

    //llenar el arreglo usando aritmetica de punteros
    cout << "Ingrese los pesos de la jornada especial:\n ";

    for (double*p = pesos; p < pesos + cantidad; ++p) {
        cout <<"Pesos: ";
        cin >> *p;
    }

    //calcular el promedio con aritmetica de punteros
    double suma = 0;
    for (double*p = pesos; p < pesos + cantidad; ++p) {
        suma += *p;
    }

    double promedio = suma / cantidad;
    cout << "El promedio de los pesos es: " << promedio << endl;

    // Liberar la memoria reservada
    delete[] pesos;
    // puntero nullptr

    pesos = nullptr;
    return 0;
}