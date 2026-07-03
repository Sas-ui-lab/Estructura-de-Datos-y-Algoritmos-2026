#include <iostream>
#include <queue>
#include <string>
#include <limits>
using namespace std;

string leerPalabra(const string& mensaje) {
    string texto;
    const size_t LONGITUD_MAXIMA = 50;

    while (true) {
        cout << mensaje;
        cin >> texto;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intente nuevamente.\n";
            continue;
        }

        if (texto.empty()) {
            cout << "Debe ingresar un nombre.\n";
            continue;
        }

        if (texto.size() > LONGITUD_MAXIMA) {
            cout << "Nombre demasiado largo (maximo "
                 << LONGITUD_MAXIMA << " caracteres).\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return texto;
    }
}

int main() {
    queue<string> cola;
    const int TOTAL_PERSONAS = 10;

    cout << "Registro de " << TOTAL_PERSONAS << " personas en espera:\n";
    for (int i = 1; i <= TOTAL_PERSONAS; i++) {
        string nombre = leerPalabra("Nombre de la persona " + to_string(i) + ": ");
        cola.push(nombre);
    }

    cout << "\n--- Atendiendo en orden FIFO ---\n";
    int turno = 1;
    while (!cola.empty()) {
        cout << "Atendiendo a: " << cola.front() << " (turno " << turno << ")\n";
        cola.pop();
        turno++;
    }

    cout << "\nTodas las personas fueron atendidas.\n";
    return 0;
}
