#include <iostream>
#include <string>
#include <vector>
#include "Libro.cpp"

using namespace std;

class Biblioteca{
    private:
        int id;
        string nombre;
        string direccion;
        vector<Libro> libros;
        Libro _libros[10];
        string telefono;
    public:
    Biblioteca(){

    Biblioteca(int _id, string _nombre, string _direccion, string _telefono){
        this->id=_id;
        this->nombre=_nombre;
        this->direccion=_direccion;
        this->telefono=_telefono;
    }   
}
    int get_id(){
        return this->id;
    }
    void set_id(int _id){
        this->id=_id;
    }
    string get_nombre(){
        return this->nombre;
    }
    void set_nombre(string _nombre){
        this->nombre=_nombre;
    }
    string get_direccion(){
        return this->direccion;
    }
    void set_direccion(string _direccion){
        this->direccion=_direccion;
    }
    string get_telefono(){
        return this->telefono;
    }
    void set_telefono(string _telefono){
        this->telefono=_telefono;
    }
    void agregar_libro(Libro _libro){
        libros.push_back(_libro);
    }
    void mostrar_libros(){
        if(libros.empty()){
            cout<<"No existen libros registrados en la biblioteca"<<endl;
        }else{
            cout<<"Lista de libros registrados en la biblioteca: "<<endl;
            cout<<"---------------------------------------------"<<endl;
            for (Libro libro : libros){
                libro.imprimir();
            }
            cout<<"---------------------------------------------"<<endl;
        }
    }
    void eliminar_libro(int _id_libro){
    }

    void prestamo(int _id_libro){
        for (Libro libro : libros){
            if (libro.get_id() == _id_libro){

            }
        }
        cout<<"No se encontró el libro con ID: "<<_id_libro<<endl;
    }
    };