
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

    // Vector donde vamos a guardar todos los logs del archivo
    vector<Log> logs;

    // Variable temporal para leer un log a la vez
    Log registro;

    // Leemos los datos de cada linea del archivo
    while (archivo >> registro.mes >> registro.dia >> registro.anio
                   >> registro.hora >> registro.ip) {

        // Leemos el resto de la linea, que es el mensaje
        getline(archivo, registro.mensaje);

        // Guardamos el log completo en el vector
        logs.push_back(registro);
    }

    // Mostramos cuantos logs se guardaron
    cout << "Se leyeron " << logs.size() << " logs." << endl;

    // Cerramos el archivo
    archivo.close();

    return 0;
}