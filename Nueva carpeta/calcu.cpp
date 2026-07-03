#include <iostream>
#include <string>
using namespace std;

void calcu() {
    cout << "--- CALCULADORA ---\n";
    
    double arregloNumeros[2]; 
    
    cout << "Ingresa el primer numero: ";
    cin >> arregloNumeros[0];
    
    cout << "Ingresa el segundo numero: ";
    cin >> arregloNumeros[1];
    
    cout << "\n¿Que operacion deseas hacer?\n";
    cout << "1. Sumar\n";
    cout << "2. Restar\n";
    cout << "Elige (1 o 2): ";

    int opcion;
    cin >> opcion;
    
    double resultado;
    
    if (opcion == 1) {
        resultado = arregloNumeros[0] + arregloNumeros[1];
        cout << "Resultado: " <<endl<< resultado << endl;
    } 
    else if (opcion == 2) {
        resultado = arregloNumeros[0] - arregloNumeros[1];
        cout << "Resultado: " <<endl << resultado << endl;
    } 
    else {
        cout << "Opcion no valida >:c \n";
    }
}

int main() {
    calcu();
    return 0;
}