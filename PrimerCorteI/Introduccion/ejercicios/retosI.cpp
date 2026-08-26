#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "=== RETO 1 ===\n\n";

    string vasoA = "Jugo de naranja";
    string vasoB = "Agua";
    string vasoC = "Vacío";

    cout << "Estado inicial\n";
    cout << "A: " << vasoA << endl;
    cout << "B: " << vasoB << endl;
    cout << "C: " << vasoC << endl;

    vasoC = vasoA;
    vasoA = "Vacío";

    vasoA = vasoB;
    vasoB = "Vacío";

    vasoB = vasoC;
    vasoC = "Vacío";

    cout << "\nEstado final\n";
    cout << "A: " << vasoA << endl;
    cout << "B: " << vasoB << endl;
    cout << "C: " << vasoC << endl;

    cout << "\nSecuencia:\n";
    cout << "1. A -> C\n";
    cout << "2. B -> A\n";
    cout << "3. C -> B\n";

    return 0;
}

