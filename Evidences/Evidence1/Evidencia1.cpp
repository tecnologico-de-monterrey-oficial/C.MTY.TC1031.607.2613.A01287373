
// Carolina Vildosola Guzman
// A01287373

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Un log es un registro de algo que paso en el sistema 
// Cada linea del archivo es un log y guarda la fecha, hora, IP y lo que paso
// Hacemos este struct para guardar juntos todos esos datos de cada log
struct Log {
    string mes;
    int dia;
    int anio;
    string hora;
    string ip;
    string mensaje;
};

int main() {

    // Abrimos el archivo que contiene los logs
    ifstream archivo("data/log607-1.txt");

    // Revisamos si el archivo se pudo abrir correctamente
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return 1;
    }

    cout << "Archivo abierto correctamente." << endl;

    archivo.close();

    return 0;
}