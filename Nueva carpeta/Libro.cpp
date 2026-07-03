#include <iostream>
#include <string>

using namespace std;

class Libro{
    private:
        int id;
        int anio;
        string titulo;
        string categoria;
        string autor;
        string editorial;
        bool prestamo;

    public:
    Libro( int _id, int _anio, string _titulo, string _autor, string _editorial, string _categoria, bool _prestamo){
        this->id=_id;
        this->anio=_anio;
        this->titulo=_titulo;
        this->autor=_autor;
        this->editorial=_editorial;
        this->categoria=_categoria;
        this->prestamo=_prestamo;

    }
    int get_id(){
        return this->id;
    }    
    void get_id(int _id){
        this->id=_id;
    }
    int get_anio(){
        return this->anio;
    }
    void set_anio(int _anio){
        this->anio=_anio;
    }
    string get_titulo(){
        return this->titulo;
    }
    void set_titulo(string _titulo){
        this->titulo=_titulo;
    }
    string get_categoria(){
        return this->categoria;
    }
    void set_categoria(string _categoria){
        this->categoria=_categoria;
    }
    string get_autor(){
        return this->autor;
    }
    void set_autor(string _autor){
        this->autor=_autor;
    }
    string get_editorial(){
        return this->editorial;
    }
    void set_editorial(string _editorial){
        this->editorial=_editorial;
    }
    bool get_prestamo(){
        return this->prestamo;
    }
    void set_prestamo(bool _prestamo){
        this->prestamo=_prestamo;
    }

    void imprimir(){
        cout<<"Libro: "<< this->titulo<< " , autor: "<< this->autor<<endl;
    }
};