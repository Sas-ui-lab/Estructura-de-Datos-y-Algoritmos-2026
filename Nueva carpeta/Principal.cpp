#include <string>
#include <iostream>
#include "Persona.cpp"

using namespace std;

int main()
{
    Persona estudiante = Persona();
    Persona estudiante_2 = Persona(2, "Simon", "Rodriguez", "Casma");
    estudiante.set_nombre("Javier");
    cout << "El nombre del estudiante es: " << estudiante.get_nombre() << endl;
    cout << "ingrese las notas para el estudiante " << estudiante.get_nombre() << endl;
    estudiante.ingresar_notas();
    estudiante.mostrar_promedio();
    return 0;

    Persona estudiantes[3];

    for (int i = 0; i < 3; i++)
    {
        string _nombre, _ap_paterno, _ap_materno;
        cout << "Ingrese el nombre" << endl;
        cin >> _nombre;
        cout << "Ingrese el apellido paterno" << endl;
        cin >> _ap_paterno;
        cout << "Ingrese el apellido materno" << endl;
        cin >> _ap_materno;
        estudiantes[i].set_id(i + 1);
        estudiantes[i].set_nombre(_nombre);
        estudiantes[i].set_ap_paterno(_ap_paterno);
        estudiantes[i].set_ap_materno(_ap_materno);
        
        Persona p = Persona(i + 1, _nombre, _ap_paterno, _ap_materno);
        estudiantes[i] = p;
    }

    return 0;
}