#include <iostream>
#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    string documento;
    bool   tieneSanciones;
public:
    Usuario(std::string n, std::string d);
    bool puedeSolicitar() const;
};

Usuario::Usuario(std::string n, std::string d)
    : nombre(n), documento(d), tieneSanciones(false) {}

bool Usuario::puedeSolicitar() const {
    return !tieneSanciones;
}

int main() {
    string nombre;
    string documento;

    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
   cout << "Ingrese el documento: ";
    std::getline:cin, documento);
(
    Usuario usuario(nombre, documento);
    cout << (usuario.puedeSolicitar()
        ? "El usuario puede solicitar."
        : "El usuario no puede solicitar.") << std::endl;

    return 0;
}
