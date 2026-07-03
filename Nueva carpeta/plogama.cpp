#include <iostream>
using namespace std;
///elabora un programa que realice las funciones de una calculadora,el sistema debe solicitar opciones al usuario (s:salir), debe contener un resultado aacomulado
int main(){
    float a;
    float b;
    float c;
    float resultado=0;

    while (c!='s'){
    cout<< "que operacion va a realizar"<<endl;
    cout<< "1. SUMA"<<endl<<"2. RESTA"<<endl<<"3. MULTIPLICACION"<<endl<<"4. DIVISION"<<endl<<"s. SALIR"<<endl;
    cin>> c;

    if (c==1){
    cout<<"usted realizara una suma"<<endl<<"ingrese su primer numero"<<endl;
    cin>> a;
    cout<<"ingrese su segundo numero"<<endl;
    cin>> b;
    resultado=a+b;
    cout<<"el número es"<<resultado<<endl;
    }

        if (c==2){
    cout<<"usted realizara una resta"<<endl<<"ingrese su primer numero"<<endl;
    cin>> a;
    cout<<"ingrese su segundo numero";
    cin>> b;
    resultado=a-b;
    cout<<"el número es"<<resultado;
    }

        if (c==3){
    cout<<"usted realizara una multiplicación"<<endl<<"ingrese su primer numero";
    cin>> a;
    cout<<"ingrese su segundo numero";
    cin>> b;
    resultado=a*b;
    cout<<"el número es"<<resultado;
        }

        if (c==s){
            broke
        }
        //en caso de fallar l
          if (c==3){
    cout<<"usted realizara una multiplicación"<<endl<<"ingrese su primer numero";
    cin>> a;
    cout<<"ingrese su segundo numero";
    cin>> b;
    resultado=a*b;
    cout<<"el número es"<<resultado;
        }
}
}