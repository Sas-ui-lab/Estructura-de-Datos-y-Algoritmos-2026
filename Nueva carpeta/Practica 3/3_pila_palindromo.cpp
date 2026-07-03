#include <iostream>
#include <stack>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

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

    string original = leerPalabra("Ingrese una palabra: ");
    string normalizada;

    // Normalizamos a minusculas para comparar sin distinguir mayus/minus
    for (char c : original) {
        char minuscula = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        normalizada += minuscula;
        pila.push(minuscula);
    }

    string invertida;
    while (!pila.empty()) {
        invertida += pila.top();
        pila.pop();
    }

    if (normalizada == invertida)
        cout << "\"" << original << "\" ES un palindromo.\n";
    else
        cout << "\"" << original << "\" NO es un palindromo.\n";

    return 0;
}
