#include <iostream>
#include <queue>
#include <string>
#include <limits>
using namespace std;

int leerEntero(const string& mensaje, int minimo, int maximo) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero entero valido.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (valor < minimo || valor > maximo) {
            cout << "Opcion fuera de rango. Ingrese un valor entre "
                 << minimo << " y " << maximo << ".\n";
            continue;
        }

        return valor;
    }
}

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
    queue<string> clientes;
    int opcion;

    do {
        cout << "\n===== SIMULACION DE BANCO =====\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Mostrar siguiente cliente\n";
        cout << "4. Mostrar cantidad de clientes\n";
        cout << "5. Salir\n";
        opcion = leerEntero("Opcion: ", 1, 5);

        switch (opcion) {
            case 1: {
                string nombre = leerPalabra("Nombre del cliente: ");
                clientes.push(nombre);
                cout << nombre << " se unio a la cola.\n";
                break;
            }

            case 2:
                if (clientes.empty()) {
                    cout << "No hay clientes para atender.\n";
                } else {
                    cout << "Atendiendo a: " << clientes.front() << endl;
                    clientes.pop();
                }
                break;

            case 3:
                if (clientes.empty())
                    cout << "No hay clientes en espera.\n";
                else
                    cout << "Siguiente cliente: " << clientes.front() << endl;
                break;

            case 4:
                cout << "Cantidad de clientes en cola: " << clientes.size() << endl;
                break;

            case 5:
                cout << "Cerrando el banco...\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}
