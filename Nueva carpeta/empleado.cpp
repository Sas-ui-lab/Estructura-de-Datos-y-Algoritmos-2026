#include <iostream>
#include <string>
#include <list>
#include <fstream> 
#include <sstream> 

using namespace std;

class Empleado {
    protected: 
        string cargo;
        int id;
        string nombre;
        string ap_pat;
        string ap_mat;
        string tipo;
        float anios_trab;
        float salario;
        
    public:
    
        Empleado(int _id, string _nombre, string _ap_pat, string _ap_mat, string _tipo, string _cargo, float _anios_trab) {
            this->id=_id;
            this->nombre=_nombre;
            this->ap_pat=_ap_pat;
            this->ap_mat=_ap_mat;
            this->tipo=_tipo;
            this->cargo=_cargo;
            this->anios_trab=_anios_trab;
            this->salario=0; 
        }

        
        Empleado() : id(0), nombre(""), ap_pat(""), ap_mat(""), tipo(""), cargo(""), anios_trab(0.0), salario(0.0) {}

        void calcular_salario() {
            if (tipo=="planta"){
                if (cargo=="gerente"){
                    salario = 100 * 40;
                }
                else if (cargo=="supervisor"){
                    salario = 80 * 40;
                }
                else if (cargo=="operario") { 
                    salario = 50 * 40; 
                }
            }
            else if (tipo=="hora"){
                if (cargo=="operario"){
                    salario = 50 * 40;
                }
                else if (cargo=="gerente") { 
                    salario = 100 * 40; 
                }
                else if (cargo=="supervisor") { 
                    salario = 80 * 40; 
                }
            }
        }

        float get_salario(){ return salario; }
        float get_anios_trab(){ return anios_trab; }
        string get_cargo(){ return cargo; }
        string get_nombre(){ return nombre; }
        int get_id(){ return id; }
        string get_ap_pat(){ return ap_pat; }
        string get_ap_mat(){ return ap_mat; }
        string get_tipo(){ return tipo; }

        
        void set_id(int _id) { id = _id; }
        void set_nombre(string _nombre) { nombre = _nombre; }
        void set_ap_pat(string _ap_pat) { ap_pat = _ap_pat; }
        void set_ap_mat(string _ap_mat) { ap_mat = _ap_mat; }
        void set_tipo(string _tipo) { tipo = _tipo; }
        void set_cargo(string _cargo) { cargo = _cargo; }
        void set_anios_trab(float _anios_trab) { anios_trab = _anios_trab; }
        void set_salario(float _salario) { salario = _salario; }
};

class EmpleadoPlanta : public Empleado {
    public:
        EmpleadoPlanta(int _id, string _nombre, string _ap_pat, string _ap_mat, string _tipo, string _cargo, float _anios_trab) 
        : Empleado(_id, _nombre, _ap_pat, _ap_mat, _tipo, _cargo, _anios_trab) {
        }
        EmpleadoPlanta() : Empleado() {}
};

class EmpleadoHora : public Empleado {
    public:
        EmpleadoHora(int _id, string _nombre, string _ap_pat, string _ap_mat, string _tipo, string _cargo, float _anios_trab) 
        : Empleado(_id, _nombre, _ap_pat, _ap_mat, _tipo, _cargo, _anios_trab) {
        } 
        EmpleadoHora() : Empleado() {}
};


void guardarEmpleados(Empleado empleados[], int cantidad, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo); 
    if (archivo.is_open()) {
        for (int i = 0; i < cantidad; ++i) {
            archivo << empleados[i].get_id() << ","
                    << empleados[i].get_nombre() << ","
                    << empleados[i].get_ap_pat() << ","
                    << empleados[i].get_ap_mat() << ","
                    << empleados[i].get_tipo() << ","
                    << empleados[i].get_cargo() << ","
                    << empleados[i].get_anios_trab() << ","
                    << empleados[i].get_salario() << endl;
        }
        archivo.close();
        cout << "Datos de empleados guardados en " << nombreArchivo << endl;
    } else {
        cout << "Error: No se pudo abrir el archivo " << nombreArchivo << " para escritura." << endl;
    }
}


int cargarEmpleados(Empleado empleados[], int max_cantidad, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); 
    string linea;
    int count = 0;

    if (archivo.is_open()) {
        while (getline(archivo, linea) && count < max_cantidad) {
            stringstream ss(linea);
            string segmento;

            getline(ss, segmento, ','); empleados[count].set_id(stoi(segmento));
            getline(ss, segmento, ','); empleados[count].set_nombre(segmento);
            getline(ss, segmento, ','); empleados[count].set_ap_pat(segmento);
            getline(ss, segmento, ','); empleados[count].set_ap_mat(segmento);
            getline(ss, segmento, ','); empleados[count].set_tipo(segmento);
            getline(ss, segmento, ','); empleados[count].set_cargo(segmento);
            getline(ss, segmento, ','); empleados[count].set_anios_trab(stof(segmento));
            getline(ss, segmento, ','); empleados[count].set_salario(stof(segmento));
            
            count++;
        }
        archivo.close();
        cout << count << " empleados cargados desde " << nombreArchivo << endl;
    } else {
        cout << "Advertencia: No se pudo abrir el archivo " << nombreArchivo << " o no existe. Se usaran datos por defecto." << endl;
    }
    return count;
}

int main(){
    const int MAX_EMPLEADOS = 10;
    Empleado empleados[MAX_EMPLEADOS];
    int num_empleados_actual = 0;

    
    num_empleados_actual = cargarEmpleados(empleados, MAX_EMPLEADOS, "empleados.txt");

    
    if (num_empleados_actual == 0) {
        cout << "Inicializando con datos de ejemplo..." << endl;
        empleados[0] = Empleado(1, "Sayury", "Lazo", "Gonzales", "planta", "gerente", 14);
        empleados[1] = Empleado(2, "Dayana", "Ramos", "Retis", "planta", "supervisor", 30);
        empleados[2] = Empleado(3, "Maria", "Rodriguez", "Lopez", "hora", "operario", 1);
        empleados[3] = Empleado(4, "Juan", "Martinez", "Sanchez", "planta", "gerente", 17);
        empleados[4] = Empleado(5, "Ana", "Garcia", "Fernandez", "planta", "supervisor", 10);
        empleados[5] = Empleado(6, "Luis", "Hernandez", "Diaz", "hora", "operario", 19);
        empleados[6] = Empleado(7, "Laura", "Torres", "Ruiz", "planta", "gerente", 20);
        empleados[7] = Empleado(8, "Diego", "Silva", "Mendoza", "planta", "supervisor", 21);
        empleados[8] = Empleado(9, "Sofia", "Vargas", "Castro", "hora", "operario", 24);
        empleados[9] = Empleado(10, "Miguel", "Ramirez", "Ortiz", "planta", "gerente", 30);
        num_empleados_actual = MAX_EMPLEADOS;
    }

    for (int i=0; i<num_empleados_actual; i++){
        empleados[i].calcular_salario();
    }

    int opcion;
    do {
        cout << "\n================ MENU DE OPCIONES ================" << endl;
        cout << "1. Mostrar lista de empleados y sus salarios" << endl;
        cout << "2. Mostrar empleado con mayor salario" << endl;
        cout << "3. Mostrar empleado con mayor tiempo en la empresa" << endl;
        cout << "4. Ordenar y mostrar empleados por cargo" << endl;
        cout << "5. Guardar empleados en archivo" << endl; 
        cout << "6. Cargar empleados desde archivo" << endl; 
        cout << "7. Salir" << endl; 
        cout << "Seleccione una opcion (1-7): ";
        cin >> opcion;
        cout << "\n--------------------------------------------------" << endl;

        switch(opcion) {
            case 1:
                for (int i=0; i<num_empleados_actual; i++){
                    cout << "ID: " << empleados[i].get_id() << ", Empleado: " << empleados[i].get_nombre() << " " << empleados[i].get_ap_pat() << " - Cargo: " << empleados[i].get_cargo() << " - Salario: $" << empleados[i].get_salario() << endl;
                }
                break;

            case 2: {
                if (num_empleados_actual == 0) break;
                Empleado* empleado_mayor_salario = &empleados[0];
                for (int i=1; i<num_empleados_actual; i++){
                    if (empleados[i].get_salario() > empleado_mayor_salario->get_salario()){
                        empleado_mayor_salario = &empleados[i];
                    }
                }
                cout << "Empleado con mayor salario: " << empleado_mayor_salario->get_nombre() << " - Salario: $" << empleado_mayor_salario->get_salario() << endl;
                break;
            }

            case 3: {
                if (num_empleados_actual == 0) break;
                Empleado* empleado_mayor_tiempo = &empleados[0];
                for (int i=1; i<num_empleados_actual; i++){
                    if (empleados[i].get_anios_trab() > empleado_mayor_tiempo->get_anios_trab()){
                        empleado_mayor_tiempo = &empleados[i];
                    }
                }
                cout << "Empleado con mayor tiempo en la empresa: " << empleado_mayor_tiempo->get_nombre() << " - Anios de trabajo: " << empleado_mayor_tiempo->get_anios_trab() << endl;
                break;
            }

            case 4:
                if (num_empleados_actual == 0) break;
                for (int i=0; i<num_empleados_actual; i++){
                    for (int j=0; j<num_empleados_actual - 1; j++){
                        if (empleados[j].get_cargo() > empleados[j+1].get_cargo()){
                            Empleado temp = empleados[j];
                            empleados[j] = empleados[j+1];
                            empleados[j+1] = temp;
                        }
                    }
                }
                cout << "Empleados ordenados por cargo: " << endl;
                for (int i=0; i<num_empleados_actual; i++){
                    cout << "Empleado: " << empleados[i].get_nombre() << " - Cargo: " << empleados[i].get_cargo() << endl;
                }
                break;

            case 5: 
                guardarEmpleados(empleados, num_empleados_actual, "empleados.txt");
                break;

            case 6: 
                num_empleados_actual = cargarEmpleados(empleados, MAX_EMPLEADOS, "empleados.txt");
                for (int i=0; i<num_empleados_actual; i++){
                    empleados[i].calcular_salario();
                }
                break;

            case 7:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "OPCION NO VALIDA, INTENTE DE NUEVO. " << endl;
        }
        cout << "--------------------------------------------------" << endl;

    } while(opcion != 7);

    return 0;
}