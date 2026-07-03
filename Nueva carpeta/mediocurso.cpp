// Autor: Sayury Lazo Gonzales
// Fecha: 28/05/2026

// se requiere un programa que permita gestionar el salario de un empleado con muchas opciones
#include <iostream> //libreria para entrada y salida de datos
#include <string> //libreria para manejo de cadenas de texto
using namespace std;//para no tener que escribir std:: antes de cada funcion de la libreria

//variables 
//nombre del empleado
string nombre;
//apellido paterno del empleado
string apellido_pat;
//apellido materno del empleado
string apellido_mat;
//id del empleado
string id;
//ingresar horas trabajadas
int horasTra;
//mostrar salario (120$ por hora)
float salario;
//descuento por seguro de salud(-120$)
float descuentoSalud;
//descuento afp(-150$)
float descuentoAFP;
//beneficio por movilidad(+500$)
float beneficioMov;
//beneficio por alimentación(+1000$)
float beneficioAlim;
//opcion para salir del programa
char opcion;

int main() {//funcion principal del programa
// bucle para ingresar datos de varios empleados
    while (true) {// el programa se ejecutará indefinidamente hasta que el usuario decida salir
        // mostrar menu de opciones para ingresar datos del empleado
        cout << "\n======= REGISTRO DE EMPLEADO =======\n";
        cout << "Ingrese el nombre del empleado: ";
        cin >> nombre;
        cout << "Ingrese apellido paterno del empleado: ";
        cin >> apellido_pat;
        cout << "Ingrese apellido materno del empleado: ";
        cin >> apellido_mat;
        cout << "Ingrese el ID del empleado: ";
        cin >> id;
        cout << "Ingrese las horas trabajadas: ";
        cin >> horasTra;

        // calcular salario y beneficios/descuentos
        salario = horasTra * 120;
        descuentoSalud = -120;
        descuentoAFP = -150;
        beneficioMov = 500;
        beneficioAlim = 1000;

        //  boleta de pago
        cout << "\n==================================================\n";
        cout << "                  BOLETA DE PAGO                  \n";
        cout << "==================================================\n";
        cout << "Nombre: " << nombre << " " << apellido_pat << " " << apellido_mat << endl;
        cout << "ID: " << id << endl;
        cout << "--------------------------------------------------\n";
        cout << "Salario bruto: " << salario << endl;
        cout << "Descuento por seguro de salud: " << descuentoSalud << endl;
        cout << "Descuento por AFP: " << descuentoAFP << endl;
        cout << "SUELDO NETO: " << salario + descuentoSalud + descuentoAFP << endl;// el sueldo neto se calcula sumando el salario bruto con los descuentos (que son negativos)
        cout << "--------------------------------------------------\n";
        cout << "Beneficio por movilidad: " << beneficioMov << endl;
        cout << "Beneficio por alimentacion: " << beneficioAlim << endl;
        cout << "TOTAL NETO PAGAR: " << salario + descuentoSalud + descuentoAFP + beneficioMov + beneficioAlim << endl;// el total neto a pagar se calcula sumando el salario bruto con los descuentos y beneficios
        cout << "==================================================\n";
        
        // preguntar si desea salir del programa o ingresar otro empleado
        cout << "\nDesea salir del programa? (s/n): ";
        cin >> opcion;

        // manejar la opcion del usuario
        if (opcion == 's' || opcion == 'S') { // si el usuario ingresa s o S, se sale del programa
            cout << "Saliendo del programa..." << endl;
            break; // salir del bucle y terminar el programa

            // si el usuario ingresa n o N, se reinicia el programa para ingresar otro empleado
        } else if (opcion == 'n' || opcion == 'N') { 
            cout << "Preparando el sistema para el siguiente empleado..." << endl;
            // el programa continuara en el bucle y se reiniciara la pregunta de si desea salir o continuar el programa
        } else {
            cout << "Opción no válida. Por favor, ingrese 's' para salir o 'n' para continuar." << endl;
        }
    }

    return 0; // indica que el programa termin correctamente
}