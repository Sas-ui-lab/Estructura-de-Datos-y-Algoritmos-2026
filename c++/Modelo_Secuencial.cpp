#include <iostream>
#include <chrono>
#include <thread>
#include <string> 

using namespace std;

void tarea(const string &nombre, int segundos) {
    cout << "[INICIO] " << nombre << "\n";
    this_thread::sleep_for(chrono::seconds(segundos)); // Simula trabajo
    cout << "[FIN]    " << nombre << "\n";
}

int main() {
    // Las tareas se llaman una por una, en orden
    tarea("Descargar datos", 2);
    tarea("Procesar datos", 1);
    tarea("Guardar resultados", 1);

    cout << "Tiempo total: ~4 segundos" << endl;
    
    return 0;
}