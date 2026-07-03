#include <iostream>
#include <string>
using namespace std;

class Persona{}
    private:
        int id;
        string nombre;
        string ap_pat;
        string ap_mat;
        string dni;
        string direccion;
        string telefono;
        string correo;
        float notas[3];
        //metodos
    public:
    Persona(){

    Persona(int id, string nombre, string ap_pat, string ap_mat, string dni, string direccion, string telefono, string correo){
        this->id=id;
        this->nombre=nombre;
        this->ap_pat=ap_pat;
        this->ap_mat=ap_mat;
    
    }

    void set_id(int _id){
        this->id=_id;
    }


    string get_ap_pat(){
        return this->ap_pat;
    }
    void ingresar_nota(int i, float _nota){
        notas[i]=_nota;
    }

    float promedio(){
        float suma=0;
        for (int i=0; i<3; i++){
            suma= suma +notas[i];
        }
        return suma/3;
    }
};

int main(){

    Persona estudiante = Persona();
    Persona estudiante_2 = Persona(2, "Simon", "Rodriguez", "Casma");

    estudiante.set_nombre("Javier");

    cout << "el nombre del estudiante es: " << estudiante.get_nombre() << endl;

    cout<< "ingrese las notas del estudiante: "<<estudiante.get_nombre()<<endl;
    for(int i=0; i<3; i++){

        float nota =0;
        cout<< "ingrese la nota "<<i+1<<": ";
        cin>>nota;
        estudiante.ingresar_nota(i, nota);
    }

    cout<< "el promedio del estudiante es: "<<estudiante.promedio()<<endl;


    return 0;
}