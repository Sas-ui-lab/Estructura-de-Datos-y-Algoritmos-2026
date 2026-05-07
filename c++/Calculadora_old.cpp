//diseñen un programa que simplule una calculadora, suma,resta,multiplicacion y division
#include <iostream>

using namespace std;

int main(){
    float a;
    float b;
    float c;



    cout<< "que operación va a realizar";
    cout<< "1. SUMA"<<"2. RESTA"<<"3. MULTIPLICACIÓN"<<"4. DIVISION";
    cin>> c;

    if (c=1){
    cout<<"usted realizara una suma";
    cout<<"ingrese su primer numero";
    cin>> a;
    cout<<"ingrese su segundo numero";
    cin>> b;
    cout<<a+b;
    }

        if (c=2){
    cout<<"usted realizara una resta";
    cout<<"ingrese su primer numero";
    cin>> a;
    cout<<"ingrese su segundo numero";
    cin>> b;
    cout<<a-b;
    }

        if (c=3){
    cout<<"usted realizara una multiplicación";
    cout<<"ingrese su primer numero";
    cin>> a;
    cout<<"ingrese su segundo numero";
    cin>> b;
    cout<<a*b;
    }
}


