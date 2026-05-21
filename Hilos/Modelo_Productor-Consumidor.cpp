#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono> // Necesario para sleep_for

using namespace std;

queue<int> cola;
mutex mtx;
condition_variable cv;
bool fin_produccion = false;

void productor(int n) {
    for (int i = 1; i <= n; i++) {
        this_thread::sleep_for(chrono::milliseconds(200));
        {
            lock_guard<mutex> lock(mtx);
            cola.push(i);
            cout << "Producido: " << i << endl;
        }
        cv.notify_one(); // Avisa al consumidor que hay algo nuevo
    }
    
    {
        lock_guard<mutex> lock(mtx);
        fin_produccion = true;
    }
    cv.notify_one(); // Avisa que ya terminamos de producir
}

void consumidor() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        
        // Espera hasta que haya datos O se acabe la producción
        cv.wait(lock, [] { return !cola.empty() || fin_produccion; });

        while (!cola.empty()) {
            int val = cola.front();
            cola.pop();
            cout << "   Consumido: " << val << endl;
        }

        if (fin_produccion && cola.empty()) {
            break;
        }
    }
}

int main() {
    thread prod(productor, 5);
    thread cons(consumidor);
    
    prod.join(); 
    cons.join();
    
    cout << "Sistema finalizado correctamente." << endl;
    return 0;
}