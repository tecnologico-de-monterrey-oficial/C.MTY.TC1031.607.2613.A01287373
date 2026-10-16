
// Carolina Vildósola Guzmán A01287373

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>

#include "../include/Queue.h"
#include "../include/Log.h"

using namespace std;

// Guardamos la linea y su numero para reportar errores
struct LineaLog {
    string texto;
    int numero;
};

// Revisamos si la fecha es valida
bool fechaValida(const Log& log) {
    int mes = log.numeroMes();

    if (mes == 0 || log.anio < 1) {
        return false;
    }

    int diasMes[] = {31, 28, 31, 30, 31, 30,
                     31, 31, 30, 31, 30, 31};

    bool bisiesto = (log.anio % 400 == 0 ||
                    (log.anio % 4 == 0 && log.anio % 100 != 0));

    if (bisiesto) {
        diasMes[1] = 29;
    }

    return log.dia >= 1 && log.dia <= diasMes[mes - 1];
}

// Revisamos que la hora tenga formato HH:MM:SS
bool horaValida(const string& hora) {
    if (hora.length() != 8 || hora[2] != ':' || hora[5] != ':') {
        return false;
    }

    for (int i = 0; i < 8; i++) {
        if (i == 2 || i == 5) {
            continue;
        }

        if (!isdigit(static_cast<unsigned char>(hora[i]))) {
            return false;
        }
    }

    int horas = stoi(hora.substr(0, 2));
    int minutos = stoi(hora.substr(3, 2));
    int segundos = stoi(hora.substr(6, 2));

    return horas >= 0 && horas <= 23 &&
           minutos >= 0 && minutos <= 59 &&
           segundos >= 0 && segundos <= 59;
}

// Revisamos que la IP tenga cuatro numeros entre 0 y 255
bool ipValida(const string& ip) {
    stringstream ss(ip);
    string parte;
    int cantidad = 0;

    while (getline(ss, parte, '.')) {
        if (parte.empty() || parte.length() > 3) {
            return false;
        }

        for (char caracter : parte) {
            if (!isdigit(static_cast<unsigned char>(caracter))) {
                return false;
            }
        }

        int numero = stoi(parte);

        if (numero < 0 || numero > 255) {
            return false;
        }

        cantidad++;
    }

    return cantidad == 4 && !ip.empty() && ip.back() != '.';
}

// Convertimos una linea de texto en un Log
bool convertirLog(const string& linea, Log& log, string& motivo) {
    stringstream ss(linea);

    if (!(ss >> log.mes >> log.dia >> log.anio
             >> log.hora >> log.ip)) {
        motivo = "Faltan datos del registro";
        return false;
    }

    getline(ss >> ws, log.descripcion);

    if (!fechaValida(log)) {
        motivo = "Fecha invalida";
        return false;
    }

    if (!horaValida(log.hora)) {
        motivo = "Hora invalida";
        return false;
    }

    if (!ipValida(log.ip)) {
        motivo = "IP invalida";
        return false;
    }

    if (log.descripcion.empty()) {
        motivo = "Descripcion vacia";
        return false;
    }

    return true;
}

int main() {

    Queue<LineaLog> fila;

    string nombreArchivo;
    int opcion;

    cout << "Archivos:" << endl;
    cout << "1. log607-1.txt" << endl;
    cout << "2. log607-2.txt" << endl;
    cout << "Selecciona un archivo: ";

    if (!(cin >> opcion)) {
        cout << "Opcion invalida" << endl;
        return 0;
    }

    if (opcion == 1) {
        nombreArchivo = "log607-1.txt";
    }
    else if (opcion == 2) {
        nombreArchivo = "log607-2.txt";
    }
    else {
        cout << "Opcion invalida" << endl;
        return 0;
    }

    // Abrimos el archivo desde la carpeta data
    ifstream archivo("../data/" + nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: "
             << nombreArchivo << endl;
        return 0;
    }

    // Leemos cada linea y la guardamos en nuestra fila
    string linea;
    int numeroLinea = 0;

    while (getline(archivo, linea)) {
        numeroLinea++;

        LineaLog registro;
        registro.texto = linea;
        registro.numero = numeroLinea;

        fila.enqueue(registro);
    }

    archivo.close();

    cout << "\nArchivo: " << nombreArchivo << endl;
    cout << "Lineas leidas: " << numeroLinea << endl;
    cout << "Lineas en la fila: " << fila.getSize() << endl;

    // Sacamos las lineas de la fila y las convertimos en Log
    int cargados = 0;
    int omitidos = 0;

    while (!fila.isEmpty()) {
        LineaLog actual = fila.dequeue();

        Log log;
        string motivo;

        if (convertirLog(actual.texto, log, motivo)) {
            log.ordenLlegada = cargados;
            cargados++;
        }
        else {
            omitidos++;

            cout << "Linea " << actual.numero
                 << " omitida: " << motivo << endl;
        }
    }

    cout << "\nResultado de la lectura" << endl;
    cout << "Registros validos: " << cargados << endl;
    cout << "Lineas omitidas: " << omitidos << endl;

    return 0;
}