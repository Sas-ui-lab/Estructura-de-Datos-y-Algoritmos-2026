#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <limits>
using namespace std;

struct Ticket {
    int codigo;
    string cliente;
    int prioridad; // 1 = alta, 2 = media, 3 = baja
};

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
            cout << "Valor fuera de rango. Ingrese un valor entre "
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

char leerSiNo(const string& mensaje) {
    char respuesta;
    while (true) {
        cout << mensaje;
        cin >> respuesta;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        respuesta = static_cast<char>(tolower(static_cast<unsigned char>(respuesta)));

        if (respuesta != 's' && respuesta != 'n') {
            cout << "Respuesta invalida. Escriba 's' o 'n'.\n";
            continue;
        }

        return respuesta;
    }
}

int main() {
    list<Ticket> tickets; // lista ordenada por prioridad
    int contador = 1;
    char continuar;

    do {
        Ticket t;
        t.codigo = contador++;
        t.cliente = leerPalabra("\nCliente: ");
        t.prioridad = leerEntero("Prioridad (1=Alta, 2=Media, 3=Baja): ", 1, 3);

        // Insercion ordenada manual: recorremos la lista hasta encontrar
        // el lugar correcto segun prioridad.
        auto it = tickets.begin();
        while (it != tickets.end() && it->prioridad <= t.prioridad)
            ++it;
        tickets.insert(it, t);

        continuar = leerSiNo("Desea agregar otro ticket? (s/n): ");

    } while (continuar == 's');

    // Pasamos la lista ya ordenada a una pila para mostrar el orden
    // de atencion respetando la prioridad registrada.
    stack<Ticket> pilaInversa;
    for (auto it = tickets.rbegin(); it != tickets.rend(); ++it)
        pilaInversa.push(*it);

    cout << "\n--- Orden de atencion segun prioridad ---\n";
    while (!pilaInversa.empty()) {
        Ticket actual = pilaInversa.top();
        pilaInversa.pop();

        string nivel = (actual.prioridad == 1) ? "Alta" :
                       (actual.prioridad == 2) ? "Media" : "Baja";

        cout << "Codigo: " << actual.codigo
             << " | Cliente: " << actual.cliente
             << " | Prioridad: " << nivel << endl;
    }

    return 0;
}
