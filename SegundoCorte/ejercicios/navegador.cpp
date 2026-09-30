#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> atras, adelante;
string actual = "inicio.com";

void visitar(const string& url) {
    atras.push(actual);
    actual = url;
    while (!adelante.empty()) adelante.pop();
    cout << "Visitar   -> " << actual << "\n";
}

void irAtras() {
    if (atras.empty()) { cout << "No hay pagina anterior\n"; return; }
    adelante.push(actual);
    actual = atras.top(); atras.pop();
    cout << "Atras     -> " << actual << "\n";
}

void irAdelante() {
    if (adelante.empty()) { cout << "No hay pagina siguiente\n"; return; }
    atras.push(actual);
    actual = adelante.top(); adelante.pop();
    cout << "Adelante  -> " << actual << "\n";
}

int main() {
    visitar("google.com");
    visitar("wikipedia.org");
    visitar("youtube.com");
    irAtras();
    irAtras();
    irAdelante();
    visitar("github.com");
    irAdelante();
    return 0;
}