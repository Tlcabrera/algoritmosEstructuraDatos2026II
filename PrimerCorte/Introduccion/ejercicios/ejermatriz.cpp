/*Problema: una biblioteca comunitaria presta 3 
recursos (computador, videobeam, sala) 
durante 5 días. Se quiere saber cuánto 
se usó cada recurso 
y qué tan cargado estuvo cada día.*/
#include <iostream>
using namespace std;
 
int main() {
    const int RECURSOS = 3;
    const int DIAS     = 5;
 
    int uso[RECURSOS][DIAS] = {
        { 4, 2, 6, 1, 3 },
        { 0, 5, 5, 2, 7 },
        { 8, 1, 0, 4, 2 }
    };
 
    cout << "Total por recurso (filas):" << endl;
    for (int i = 0; i < RECURSOS; i++) {
        int total = 0;
        for (int j = 0; j < DIAS; j++) total += uso[i][j];
        cout << "  Recurso " << i << ": " << total << endl;
    }
 
    cout << "Total por dia (columnas):" << endl;
    for (int j = 0; j < DIAS; j++) {      // ojo: j por fuera
        int total = 0;
        for (int i = 0; i < RECURSOS; i++) total += uso[i][j];
        cout << "  Dia " << j << ": " << total << endl;
    }
    return 0;
}
