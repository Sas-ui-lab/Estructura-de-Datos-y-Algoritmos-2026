haz un codigo basico con listas enlazadas en c++
#include <iostream>
#include <string>
using namespace std;
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};
class ListaEnlazada {
private:
    Nodo* cabeza;
public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    
