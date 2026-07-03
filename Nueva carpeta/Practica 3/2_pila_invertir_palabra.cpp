#include <iostream>
#include <stack>
#include <string>
#include <limits>
using namespace std;

// Lee una palabra validando que no este vacia, que no falle el stream
// y limitando su longitud como medida de seguridad basica (evita
// reservar memoria excesiva ante una entrada anomala).
string leerPalabra(const string& mensaje) {
    string palabra;
    const size_t LONGITUD_MAXIMA = 100;

    while (true) {
        cout << mensaje;
        cin >> palabra;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intente nuevamente.\n";
            continue;
        }

        if (palabra.empty()) {
            cout << "Debe ingresar una palabra.\n";
            continue;
        }

        if (palabra.size() > LONGITUD_MAXIMA) {
            cout << "La palabra es demasiado larga (maximo "
                 << LONGITUD_MAXIMA << " caracteres).\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return palabra;
    }
}

int main() {
    stack<char> pila;

    string palabra = leerPalabra("Ingrese una palabra: ");

    for (char c : palabra)
        pila.push(c);

    cout << "Palabra invertida: ";
    while (!pila.empty()) {
        cout << pila.top();
        pila.pop();
    }
    cout << endl;

    return 0;
}
