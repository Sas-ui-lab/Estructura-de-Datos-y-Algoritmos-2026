#include <iostream>
#include <stack>
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
    const size_t LONGITUD_MAXIMA = 200;

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
            cout << "Debe ingresar un valor.\n";
            continue;
        }

        if (texto.size() > LONGITUD_MAXIMA) {
            cout << "Texto demasiado largo (maximo "
                 << LONGITUD_MAXIMA << " caracteres).\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return texto;
    }
}

int main() {
    stack<string> historial;
    int opcion;
    string pagina;

    do {
        cout << "\n===== NAVEGADOR =====\n";
        cout << "1. Visitar pagina\n";
        cout << "2. Retroceder\n";
        cout << "3. Mostrar pagina actual\n";
        cout << "4. Salir\n";
        opcion = leerEntero("Opcion: ", 1, 4);

        switch (opcion) {
            case 1:
                pagina = leerPalabra("Ingrese la URL/pagina a visitar: ");
                historial.push(pagina);
                cout << "Visitando: " << pagina << endl;
                break;

            case 2:
                if (historial.empty()) {
                    cout << "No hay paginas para retroceder.\n";
                } else {
                    string actual = historial.top();
                    historial.pop();
                    cout << "Saliendo de: " << actual << endl;
                    if (!historial.empty())
                        cout << "Ahora estas en: " << historial.top() << endl;
                    else
                        cout << "No hay pagina anterior. Historial vacio.\n";
                }
                break;

            case 3:
                if (historial.empty())
                    cout << "No hay ninguna pagina visitada aun.\n";
                else
                    cout << "Pagina actual: " << historial.top() << endl;
                break;

            case 4:
                cout << "Cerrando navegador...\n";
                break;
        }

    } while (opcion != 4);

    return 0;
}
