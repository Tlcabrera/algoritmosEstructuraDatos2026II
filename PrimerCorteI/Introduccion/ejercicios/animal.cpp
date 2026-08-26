#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void hacerSonido()
    {
        cout << "El animal hace un sonido." << endl;
    }
};

class Perro : public Animal
{
public:
    void hacerSonido() override
    {
        cout << "El perro ladra." << endl;
    }
};

class Gato : public Animal
{
public:
    void hacerSonido() override
    {
        cout << "El gato maúlla." << endl;
    }
};
