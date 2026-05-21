#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono> // Indispensable para usar chrono::milliseconds

using namespace std;

mutex mtx; // Evita salidas mezcladas en consola

void tarea(int id, int ms) {
    {
        lock_guard<mutex> lock(mtx);
        cout << "Hilo " << id << " iniciado" << endl;
    }
    
    // Simula trabajo variable
    this_thread::sleep_for(chrono::milliseconds(ms));
    
    {
        lock_guard<mutex> lock(mtx);
        cout << "Hilo " << id << " terminado" << endl;
    }
}

int main() {
    vector<thread> hilos;

    // Lanzamos 4 hilos concurrentes
    for (int i = 1; i <= 4; i++) {
        hilos.emplace_back(tarea, i, i * 300);
    }

    for (auto& h : hilos) {
        h.join(); // Esperamos que todos terminen
    }

    cout << "Todos los hilos completados" << endl;
    return 0;
}