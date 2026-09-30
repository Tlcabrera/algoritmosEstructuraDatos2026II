#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

// Evalúa una expresión en notación postfija (como las calculadoras HP)
double evaluar(const string& expr) {
    stack<double> st;
    istringstream in(expr);
    string tok;
    while (in >> tok) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            double b = st.top(); st.pop();   // ojo: primero sale el segundo operando
            double a = st.top(); st.pop();
            if (tok == "+") st.push(a + b);
            else if (tok == "-") st.push(a - b);
            else if (tok == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stod(tok));
        }
    }
    return st.top();
}

int main() {
    // (3 + 4) * 2        ->  3 4 + 2 *
    // 10 - (6 / 3)       ->  10 6 3 / -
    // (5 + 1) * (8 - 2)  ->  5 1 + 8 2 - *
    string exprs[] = {"3 4 + 2 *", "10 6 3 / -", "5 1 + 8 2 - *"};
    for (const string& e : exprs)
        cout << e << "  =  " << evaluar(e) << "\n";
    return 0;
}
// intentar incluir potencia y raiz cuadrada