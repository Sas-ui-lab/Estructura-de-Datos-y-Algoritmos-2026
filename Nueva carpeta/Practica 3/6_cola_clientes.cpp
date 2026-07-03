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
    queue<string> clientes;
    string nombre;

    cout << "Registro de clientes en cola (ingrese 'fin' para terminar):\n";
    while (true) {
        nombre = leerPalabra("Nombre del cliente: ");
        if (nombre == "fin") break;
        if (nombre.empty()) continue;
        clientes.push(nombre);
    }

    cout << "\n--- Atencion de clientes ---\n";
    while (!clientes.empty()) {
        cout << "\nCliente atendido: " << clientes.front() << endl;
        clientes.pop();

        cout << "Clientes pendientes (" << clientes.size() << "): ";
        if (clientes.empty()) {
            cout << "Ninguno.\n";
        } else {
            queue<string> copia = clientes;
            while (!copia.empty()) {
                cout << copia.front() << " ";
                copia.pop();
            }
            cout << endl;
        }

        cout << "Presione Enter para atender al siguiente...";
        cin.get();
    }

    cout << "\nNo quedan clientes por atender.\n";
    return 0;
}
