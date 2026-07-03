#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Estructura simplificada para el ejemplo
class Empleado {
public:
    int id;
    string nombre;
    string cargo;
    float salario;

    Empleado(int _id, string _nom, string _car, float _sal) 
        : id(_id), nombre(_nom), cargo(_car), salario(_sal) {}
};

// Función para GUARDAR la lista en un archivo TXT
void guardarEnArchivo(Empleado* empleados[], int cantidad) {
    ofstream archivo("empleados.txt"); // Crea o abre el archivo para escribir

    if (archivo.is_open()) {
        for (int i = 0; i < cantidad; i++) {
            // Guardamos los datos separados por comas o espacios
            archivo << empleados[i]->id << "," 
                    << empleados[i]->nombre << "," 
                    << empleados[i]->cargo << "," 
                    << empleados[i]->salario << endl;
        }
        archivo.close();
        cout << "Datos guardados exitosamente en empleados.txt" << endl;
    } else {
        cout << "Error al abrir el archivo para escribir." << endl;
    }
}

// Función para LEER la lista desde el archivo TXT
void leerDesdeArchivo() {
    ifstream archivo("empleados.txt"); // Abre el archivo para leer
    string linea;

    if (archivo.is_open()) {
        cout << "\n--- Datos leidos desde el archivo ---" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl; // Muestra la linea leida
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo o no existe." << endl;
    }
}

int main() {
    // Creamos algunos empleados de prueba
    Empleado* lista[2];
    lista[0] = new Empleado(1, "Sayury", "Gerente", 4000);
    lista[1] = new Empleado(2, "Noemi", "Supervisor", 3200);

    // 1. Guardar
    guardarEnArchivo(lista, 2);

    // 2. Leer
    leerDesdeArchivo();

    // Limpieza
    delete lista[0];
    delete lista[1];

    return 0;
}
