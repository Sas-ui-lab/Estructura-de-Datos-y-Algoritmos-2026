#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){

    //insertar datos en el diccionario
    map<string, int> est_diccionario;
    est_diccionario.insert({"Jose", 1});
    est_diccionario.insert({"Ana", 2});
    //est_diccionario.insert({"Maria", 3});
    //est_diccionario.insert({"Juana", 4});

    //est_diccionario.insert({5, "Javier"});

    cout << est_diccionario["Ana"] << endl;
    if(est_diccionario.find("Ana") != est_diccionario.end()){
        cout << "Valor encontrado" << est_diccionario["Ana"] << endl;
    }
for (const auto& [clave, valor] : est_diccionario) {
    cout << clave << ", ----> " << valor << endl;
}

    return 0;

}