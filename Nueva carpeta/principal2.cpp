#include<iostream>
#include <string>
#include <vector>
#include "Biblioteca.cpp"

using namespace std;

void opciones(){
    cout<<"----------------------------------"<<endl;
    cout<<"Sistema de Biblioteca"<<endl;
    cout<<"1. Registrar biblioteca"<<endl;
    cout<<"2. Agregar libro"<<endl;
    cout<<"3. Mostrar libros"<<endl;
    cout<<"4. Prestar libro"<<endl;
    cout<<"5. Devolver libro"<<endl;
    cout<<"6. Eliminar libro"<<endl;
    cout<<"7. Salir"<<endl;
    cout<<"----------------------------------"<<endl;
}

int main(){
    Biblioteca biblioteca = Biblioteca();
    int opcion;
    do{opciones_menu();
        cin >> opcion;
        switch (opcion){
            case 1:
                {int _id;
                string _nombre, _direccion, _telefono;
                cout<<"Ingrese el ID de la biblioteca: ";
                cin>>_id;
                cout<<"Ingrese el nombre de la biblioteca: ";
                cin>>_nombre;
                cout<<"Ingrese la direccion de la biblioteca: ";
                cin>>_direccion;
                cout<<"Ingrese el telefono de la biblioteca: ";
                cin>>_telefono;
                biblioteca.set_id(_id);
                biblioteca.set_nombre(_nombre);
                biblioteca.set_direccion(_direccion);
                biblioteca.set_telefono(_telefono);
                break;}

            case 2:
            {cout<<"Ingrese el año del libro: ";
            int _anio;
            cin>>_anio;
            cout<<"Ingrese el título del libro: ";
            string _titulo;
            cin>>_titulo;
            cout<<"Ingrese el autor del libro: ";
            string _autor;
            cin>>_autor;
            cout<<"Ingrese la editorial del libro: ";
            string _editorial;
            cin>>_editorial;
            cout<<"Ingrese la categoría del libro: ";
            string _categoria;
            cin>>_categoria;
            Libro _libro = Libro(0, _anio, _titulo, _autor, _editorial, _categoria);
            biblioteca.agregar_libro(_libro);
            break;}

            case 3:
                biblioteca.mostrar_libros();
                break;
            
            case 4:
            int idLibro;
            cout<<"Ingrese el ID del libro a prestar: ";
            cin>>idLibro;
            biblioteca.prestamo();
                break;

            case 5:
            int idLibro;
            cout<<"Ingrese el ID del libro a devolver: ";
            cin>>idLibro;
            biblioteca.devolver();
                break;

            case 6:
            int idLibro;
            cout<<"Ingrese el ID del libro a eliminar: ";
            cin>>idLibro;
            biblioteca.eliminar_libro(idLibro);
                break;

            case 7:
                cout<<"Gracias por usar el sistema de biblioteca. ¡Hasta luego!"<<endl;
                break;
        }

    }
}
