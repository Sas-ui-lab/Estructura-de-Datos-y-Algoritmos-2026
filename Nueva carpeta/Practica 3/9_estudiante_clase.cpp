#include <iostream>
#include <list>
#include <string>
#include <limits>
using namespace std;

class Estudiante {
private:
    int codigo;
    string nombre;
    int edad;
    string carrera;

public:
    Estudiante() : codigo(0), edad(0) {}

    Estudiante(int cod, string nom, int ed, string carr)
        : codigo(cod), nombre(nom), edad(ed), carrera(carr) {}

    int getCodigo() const { return codigo; }

    void mostrar() const {
        cout << "Codigo: " << codigo
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Carrera: " << carrera << endl;
    }
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
            cout << "Valor fuera de rango (" << minimo << " - " << maximo << ").\n";
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
            cout << "Este campo no puede estar vacio.\n";
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
    list<Estudiante> estudiantes;
    int opcion;

    do {
        cout << "\n===== GESTION DE ESTUDIANTES =====\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar todos los estudiantes\n";
        cout << "3. Buscar estudiante por codigo\n";
        cout << "4. Salir\n";
        opcion = leerEntero("Opcion: ", 1, 4);

        if (opcion == 1) {
            int cod = leerEntero("Codigo: ", 1, 999999);

            // Medida de seguridad: evitamos codigos duplicados
            bool duplicado = false;
            for (const auto& e : estudiantes) {
                if (e.getCodigo() == cod) {
                    duplicado = true;
                    break;
                }
            }
            if (duplicado) {
                cout << "Ya existe un estudiante con ese codigo.\n";
                continue;
            }

            string nom = leerPalabra("Nombre: ");
            int ed = leerEntero("Edad: ", 1, 120);
            string carr = leerPalabra("Carrera: ");

            estudiantes.push_back(Estudiante(cod, nom, ed, carr));
            cout << "Estudiante registrado con exito.\n";

        } else if (opcion == 2) {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes registrados.\n";
            } else {
                cout << "\n--- Lista de estudiantes ---\n";
                for (const auto& e : estudiantes)
                    e.mostrar();
            }

        } else if (opcion == 3) {
            int codBuscado = leerEntero("Ingrese el codigo a buscar: ", 1, 999999);

            bool encontrado = false;
            for (const auto& e : estudiantes) {
                if (e.getCodigo() == codBuscado) {
                    cout << "Estudiante encontrado:\n";
                    e.mostrar();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "No se encontro un estudiante con ese codigo.\n";
        }

    } while (opcion != 4);

    cout << "Saliendo del programa...\n";
    return 0;
}
