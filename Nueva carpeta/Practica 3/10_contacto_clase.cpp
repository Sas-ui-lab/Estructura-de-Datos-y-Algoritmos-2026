#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

class Contacto {
private:
    string nombre;
    string telefono;
    string correo;

public:
    Contacto() {}
    Contacto(string nom, string tel, string mail)
        : nombre(nom), telefono(tel), correo(mail) {}

    string getNombre() const { return nombre; }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << " | Telefono: " << telefono
             << " | Correo: " << correo << endl;
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
            cout << "Opcion fuera de rango (" << minimo << " - " << maximo << ").\n";
            continue;
        }

        return valor;
    }
}

string leerTexto(const string& mensaje, size_t longitudMaxima) {
    string texto;
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

        if (texto.size() > longitudMaxima) {
            cout << "Texto demasiado largo (maximo "
                 << longitudMaxima << " caracteres).\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return texto;
    }
}

// Valida que el telefono contenga unicamente digitos (medida de seguridad
// basica para evitar datos malformados o caracteres no deseados).
string leerTelefono(const string& mensaje) {
    while (true) {
        string telefono = leerTexto(mensaje, 15);

        bool soloDigitos = true;
        for (char c : telefono) {
            if (!isdigit(static_cast<unsigned char>(c))) {
                soloDigitos = false;
                break;
            }
        }

        if (!soloDigitos || telefono.size() < 6) {
            cout << "Telefono invalido. Debe contener solo digitos (minimo 6).\n";
            continue;
        }

        return telefono;
    }
}

// Validacion basica de correo: exige un '@' y un '.' despues de este,
// sin caracteres de espacio.
string leerCorreo(const string& mensaje) {
    while (true) {
        string correo = leerTexto(mensaje, 60);

        size_t posArroba = correo.find('@');
        size_t posPunto = correo.find('.', posArroba);

        bool valido = posArroba != string::npos &&
                      posArroba > 0 &&
                      posPunto != string::npos &&
                      posPunto < correo.size() - 1;

        if (!valido) {
            cout << "Correo invalido. Use el formato usuario@dominio.com\n";
            continue;
        }

        return correo;
    }
}

int main() {
    list<Contacto> agenda;
    int opcion;

    do {
        cout << "\n===== AGENDA DE CONTACTOS =====\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Buscar por nombre\n";
        cout << "3. Eliminar contacto\n";
        cout << "4. Mostrar todos los contactos\n";
        cout << "5. Salir\n";
        opcion = leerEntero("Opcion: ", 1, 5);

        if (opcion == 1) {
            string nom = leerTexto("Nombre: ", 50);

            // Medida de seguridad: evitamos nombres duplicados en la agenda
            bool duplicado = false;
            for (const auto& c : agenda) {
                if (c.getNombre() == nom) {
                    duplicado = true;
                    break;
                }
            }
            if (duplicado) {
                cout << "Ya existe un contacto con ese nombre.\n";
                continue;
            }

            string tel = leerTelefono("Telefono: ");
            string mail = leerCorreo("Correo electronico: ");

            agenda.push_back(Contacto(nom, tel, mail));
            cout << "Contacto agregado con exito.\n";

        } else if (opcion == 2) {
            string nomBuscado = leerTexto("Ingrese el nombre a buscar: ", 50);

            bool encontrado = false;
            for (const auto& c : agenda) {
                if (c.getNombre() == nomBuscado) {
                    cout << "Contacto encontrado:\n";
                    c.mostrar();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "No se encontro ningun contacto con ese nombre.\n";

        } else if (opcion == 3) {
            string nomEliminar = leerTexto("Ingrese el nombre del contacto a eliminar: ", 50);

            bool eliminado = false;
            for (auto it = agenda.begin(); it != agenda.end(); ++it) {
                if (it->getNombre() == nomEliminar) {
                    agenda.erase(it);
                    eliminado = true;
                    break;
                }
            }

            if (eliminado)
                cout << "Contacto eliminado con exito.\n";
            else
                cout << "No se encontro ningun contacto con ese nombre.\n";

        } else if (opcion == 4) {
            if (agenda.empty()) {
                cout << "La agenda esta vacia.\n";
            } else {
                cout << "\n--- Lista de contactos ---\n";
                for (const auto& c : agenda)
                    c.mostrar();
            }
        }

    } while (opcion != 5);

    cout << "Saliendo del programa...\n";
    return 0;
}
