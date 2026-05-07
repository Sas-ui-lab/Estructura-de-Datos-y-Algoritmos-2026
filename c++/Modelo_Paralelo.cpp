#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <functional> // Necesario para usar ref()

using namespace std;

void sumar_segmento(const vector<int>& datos, int inicio, int fin, long long& resultado) {
    resultado = 0;
    for (int i = inicio; i < fin; i++) {
        resultado += datos[i];
    }
}

int main() {
    const int N = 1000000;
    vector<int> datos(N, 1); // Un millón de unos

    int num_hilos = thread::hardware_concurrency(); // Núcleos disponibles
    vector<thread> hilos(num_hilos);
    vector<long long> parciales(num_hilos);

    int chunk = N / num_hilos;
    for (int i = 0; i < num_hilos; i++) {
        int inicio = i * chunk;
        int fin = (i == num_hilos - 1) ? N : inicio + chunk;
        
        // Usamos ref() para pasar el vector y el resultado por referencia
        hilos[i] = thread(sumar_segmento, ref(datos), inicio, fin, ref(parciales[i]));
    }

    for (auto& h : hilos) {
        h.join();
    }

    long long total = 0;
    for (auto p : parciales) {
        total += p;
    }

    cout << "Suma total: " << total << " (usando " << num_hilos << " hilos)" << endl;
    
    return 0;
}