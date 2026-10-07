
class TablaHash{
private:
    int cap;
    int n;
    std::vector<std::list<std::pair<std::string, std::string>>> cubetas;
public:
    TablaHash(int capacidad=8):cap(capacidad),n(0),cubetas(capacidad){}

int hashear(const string & clave) const {
        unsigned long long h = 0;
        for (unsigned char c : clave) h = (h * 31 + c) % cap;
        return (int)h;
    }
};
// _hash("EQ100") cap=8
