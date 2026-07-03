#include <iostream>
#include <stack>
#include <string>
#include <limits>
using namespace std;

// Lee un entero de forma segura. Si el usuario ingresa algo que no es un
// numero, cin.fail() se activa; limpiamos el estado de error y descartamos
// el contenido invalido del buffer para evitar un bucle infinito.
int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero entero valido.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

int main() {
    stack<int> pila;

    cout << "Ingrese numeros (escriba -1 para terminar):\n";
    while (true) {
        int numero = leerEntero("Numero: ");
        if (numero == -1) break;
        pila.push(numero);
    }

    cout << "\n--- Resultados ---\n";
    cout << "Cantidad de elementos en la pila: " << pila.size() << endl;

    // Verificamos que la pila no este vacia antes de acceder a top()
    // para evitar comportamiento indefinido.
    if (!pila.empty())
        cout << "Ultimo elemento ingresado: " << pila.top() << endl;
    else
        cout << "No se ingreso ningun elemento.\n";

    return 0;
}
