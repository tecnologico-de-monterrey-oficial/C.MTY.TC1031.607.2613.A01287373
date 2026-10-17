// Carolina Vildósola Guzmán A01287373

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <chrono>
#include <cmath>
#include <map>
#include <limits>

#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/Log.h"
#include "../include/DoublyLinkedList.h"

using namespace std;

// Guardamos la linea y su numero para reportar errores
struct LineaLog {
    string texto;
    int numero;
};

// Revisamos si la fecha es valida
bool fechaValida(const Log& log) {
    int mes = log.numeroMes();

    if (mes == 0 || log.anio < 1 || log.anio > 9999) {
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

// Revisamos que el texto tenga solo numeros
bool soloNumeros(const string& texto) {
    if (texto.empty()) {
        return false;
    }

    for (char caracter : texto) {
        if (!isdigit(static_cast<unsigned char>(caracter))) {
            return false;
        }
    }

    return true;
}

// Convertimos una linea de texto en un Log
bool convertirLog(const string& linea, Log& log, string& motivo) {
    stringstream ss(linea);

    string diaTexto;
    string anioTexto;

    if (!(ss >> log.mes >> diaTexto >> anioTexto
             >> log.hora >> log.ip)) {
        motivo = "Faltan datos del registro";
        return false;
    }

    if (!soloNumeros(diaTexto) ||
        !soloNumeros(anioTexto) ||
        diaTexto.length() > 2 ||
        anioTexto.length() != 4) {

        motivo = "Formato de fecha invalido";
        return false;
    }

    log.dia = stoi(diaTexto);
    log.anio = stoi(anioTexto);

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

// Revisamos si los registros ya estan ordenados
bool estaOrdenada(DoublyLinkedList<Log>& lista) {
    if (lista.getSize() <= 1) {
        return true;
    }

    NodeD<Log>* actual = lista.getNode(0);

    while (actual != nullptr && actual->next != nullptr) {
        if (actual->next->data < actual->data) {
            return false;
        }

        actual = actual->next;
    }

    return true;
}

// Cambiamos los datos de dos nodos
void intercambiar(NodeD<Log>* a, NodeD<Log>* b) {
    if (a == b) {
        return;
    }

    Log temporal = a->data;
    a->data = b->data;
    b->data = temporal;
}

// Buscamos el nodo de en medio
NodeD<Log>* buscarMedio(NodeD<Log>* inicio, NodeD<Log>* fin) {
    NodeD<Log>* lento = inicio;
    NodeD<Log>* rapido = inicio;

    while (rapido != fin && rapido->next != fin) {
        rapido = rapido->next;

        if (rapido != fin) {
            rapido = rapido->next;
            lento = lento->next;
        }
    }

    return lento;
}

// Acomodamos los datos alrededor del pivote
NodeD<Log>* particion(NodeD<Log>* inicio, NodeD<Log>* fin,
                       long long& comparaciones) {

    NodeD<Log>* medio = buscarMedio(inicio, fin);

    intercambiar(medio, fin);

    Log pivote = fin->data;

    NodeD<Log>* posicion = inicio;
    NodeD<Log>* actual = inicio;

    while (actual != fin) {
        comparaciones++;

        if (actual->data < pivote) {
            intercambiar(posicion, actual);
            posicion = posicion->next;
        }

        actual = actual->next;
    }

    intercambiar(posicion, fin);

    return posicion;
}

// Ordenamos usando Quick Sort
void quickSort(NodeD<Log>* inicio, NodeD<Log>* fin,
               long long& comparaciones,
               int profundidad, int& profundidadMaxima) {

    if (inicio == nullptr || fin == nullptr || inicio == fin) {
        return;
    }

    if (profundidad > profundidadMaxima) {
        profundidadMaxima = profundidad;
    }

    NodeD<Log>* pivote = particion(inicio, fin, comparaciones);

    if (pivote != inicio) {
        quickSort(inicio, pivote->prev, comparaciones,
                  profundidad + 1, profundidadMaxima);
    }

    if (pivote != fin) {
        quickSort(pivote->next, fin, comparaciones,
                  profundidad + 1, profundidadMaxima);
    }
}

// Guardamos los registros en el archivo de salida
bool guardarArchivo(DoublyLinkedList<Log>& lista) {
    ofstream salida("../out/output608.out");

    if (!salida.is_open()) {
        cout << "No se pudo crear el archivo de salida" << endl;
        return false;
    }

    NodeD<Log>* actual = lista.getNode(0);

    while (actual != nullptr) {
        Log log = actual->data;

        salida << log.mes << " "
               << setfill('0') << setw(2) << log.dia
               << setfill(' ') << " "
               << log.anio << " "
               << log.hora << " "
               << log.ip << " "
               << log.descripcion << endl;

        actual = actual->next;
    }

    salida.close();

    cout << "Archivo output608.out generado" << endl;
    return true;
}

// Revisamos si se conservo el orden de llegada
bool revisarEmpates(DoublyLinkedList<Log>& lista) {
    NodeD<Log>* actual = lista.getNode(0);

    while (actual != nullptr && actual->next != nullptr) {
        if (actual->data.claveFecha() ==
                actual->next->data.claveFecha() &&
            actual->data.ordenLlegada >
                actual->next->data.ordenLlegada) {

            return false;
        }

        actual = actual->next;
    }

    return true;
}

// Opcion 1 del menu
bool ordenarLogs(DoublyLinkedList<Log>& lista,
                 string nombreArchivo,
                 bool yaOrdenada) {

    if (lista.getSize() == 0) {
        cout << "No hay registros" << endl;
        return false;
    }

    if (yaOrdenada) {
        cout << "la lista ya esta ordenada" << endl;
        return true;
    }

    if (estaOrdenada(lista)) {
        cout << "la lista ya esta ordenada" << endl;
        guardarArchivo(lista);
        return true;
    }

    int prediccion;

    cout << "\nQue crecimiento esperas?" << endl;
    cout << "1. n log n" << endl;
    cout << "2. n^2" << endl;
    cout << "Selecciona una opcion: ";

    if (!(cin >> prediccion) ||
        (prediccion != 1 && prediccion != 2)) {
        cout << "Opcion invalida" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    long long comparaciones = 0;
    int profundidadMaxima = 0;

    NodeD<Log>* inicio = lista.getNode(0);
    NodeD<Log>* fin = lista.getNode(lista.getSize() - 1);

    auto tiempoInicio = chrono::high_resolution_clock::now();

    quickSort(inicio, fin, comparaciones, 1, profundidadMaxima);

    auto tiempoFinal = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo = tiempoFinal - tiempoInicio;

    cout << "\nRESULTADOS DEL ORDENAMIENTO" << endl;
    cout << "Algoritmo: Quick Sort" << endl;
    cout << "Archivo: " << nombreArchivo << endl;
    cout << "Registros: " << lista.getSize() << endl;
    cout << "Tiempo: " << tiempo.count() << " ms" << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Profundidad maxima: " << profundidadMaxima << endl;

    if (prediccion == 1) {
        cout << "Prediccion: n log n" << endl;
    }
    else {
        cout << "Prediccion: n^2" << endl;
    }

    if (!estaOrdenada(lista)) {
        cout << "Hubo un error al ordenar" << endl;
        return false;
    }

    cout << "La lista se ordeno correctamente" << endl;

    if (revisarEmpates(lista)) {
        cout << "Orden de llegada en empates: Conservado" << endl;
    }
    else {
        cout << "Orden de llegada en empates: No conservado" << endl;
        return false;
    }

    // Comparamos las cantidades aproximadas
    double n = lista.getSize();
    double nLogN = n * log2(n);
    double nCuadrada = n * n;

    cout << "Estimado n log n: " << nLogN << endl;
    cout << "Estimado n^2: " << nCuadrada << endl;

    double diferencia1 = abs(comparaciones - nLogN);
    double diferencia2 = abs(comparaciones - nCuadrada);

    int crecimientoObservado;

    if (diferencia1 <= diferencia2) {
        crecimientoObservado = 1;
    }
    else {
        crecimientoObservado = 2;
    }

    // Revisamos cual estimado quedo mas cerca
    if (crecimientoObservado == prediccion) {
        cout << "La prediccion fue la mas cercana" << endl;
    }
    else {
        cout << "La prediccion no fue la mas cercana" << endl;
    }

    return guardarArchivo(lista);
}

// Creamos una clave que solo incluye el dia
long long claveDia(const Log& log) {
    long long clave = log.anio;
    clave = clave * 100 + log.numeroMes();
    clave = clave * 100 + log.dia;

    return clave;
}

// Revisamos la fecha que escribe el usuario
bool leerDia(Log& fecha) {
    string texto;
    string diaTexto;
    string anioTexto;
    string sobrante;

    cout << "Escribe el dia (ejemplo: Sep 14 2024): ";

    getline(cin >> ws, texto);

    stringstream ss(texto);

    if (!(ss >> fecha.mes >> diaTexto >> anioTexto)) {
        cout << "Formato de fecha invalido" << endl;
        return false;
    }

    if (ss >> sobrante) {
        cout << "Formato de fecha invalido" << endl;
        return false;
    }

    if (!soloNumeros(diaTexto) ||
        !soloNumeros(anioTexto) ||
        diaTexto.length() > 2 ||
        anioTexto.length() != 4) {

        cout << "Formato de fecha invalido" << endl;
        return false;
    }

    fecha.dia = stoi(diaTexto);
    fecha.anio = stoi(anioTexto);

    if (!fechaValida(fecha)) {
        cout << "Fecha invalida" << endl;
        return false;
    }

    return true;
}

// Opcion 2: buscar registros por dia
void buscarDia(DoublyLinkedList<Log>& lista,
               bool ordenada,
               Log& ultimaFecha,
               bool& busquedaRealizada) {

    if (!ordenada) {
        cout << "Primero debes ordenar los registros con la opcion 1"
             << endl;
        return;
    }

    Log fecha;

    if (!leerDia(fecha)) {
        return;
    }

    ultimaFecha = fecha;
    busquedaRealizada = true;

    long long diaBuscado = claveDia(fecha);
    int encontrados = 0;

    NodeD<Log>* actual = lista.getNode(0);

    cout << "\nREGISTROS ENCONTRADOS" << endl;

    while (actual != nullptr) {
        long long diaActual = claveDia(actual->data);

        if (diaActual == diaBuscado) {
            actual->data.mostrar();
            encontrados++;
        }

        // Ya pasamos el dia que buscamos
        if (diaActual > diaBuscado) {
            break;
        }

        actual = actual->next;
    }

    if (encontrados == 0) {
        cout << "No hay registros para ese dia" << endl;
    }

    cout << "Total encontrado: " << encontrados << endl;
}

// Opcion 3: mostrar registros al reves con pila
void mostrarDescendente(DoublyLinkedList<Log>& lista,
                        bool ordenada,
                        Log& ultimaFecha,
                        bool& busquedaRealizada) {

    if (!ordenada) {
        cout << "Primero debes ordenar los registros con la opcion 1"
             << endl;
        return;
    }

    if (!busquedaRealizada) {
        cout << "Primero necesitamos seleccionar un dia" << endl;

        if (!leerDia(ultimaFecha)) {
            return;
        }

        busquedaRealizada = true;
    }

    Stack<Log> pila;
    long long diaBuscado = claveDia(ultimaFecha);

    NodeD<Log>* actual = lista.getNode(0);

    while (actual != nullptr) {
        long long diaActual = claveDia(actual->data);

        if (diaActual == diaBuscado) {
            pila.push(actual->data);
        }

        if (diaActual > diaBuscado) {
            break;
        }

        actual = actual->next;
    }

    int total = pila.getSize();

    cout << "\nREGISTROS EN ORDEN DESCENDENTE" << endl;

    while (!pila.isEmpty()) {
        Log log = pila.pop();
        log.mostrar();
    }

    if (total == 0) {
        cout << "No hay registros para ese dia" << endl;
    }

    cout << "Total encontrado: " << total << endl;
}

// Mostramos todos los elementos que tengan la mayor frecuencia
void mostrarMayor(map<string, int>& datos) {
    int mayor = 0;

    for (auto dato : datos) {
        if (dato.second > mayor) {
            mayor = dato.second;
        }
    }

    for (auto dato : datos) {
        if (dato.second == mayor) {
            cout << dato.first << ": " << dato.second << endl;
        }
    }
}

// Opcion 4: estadisticas del archivo
void mostrarEstadisticas(DoublyLinkedList<Log>& lista) {
    map<string, int> dias;
    map<string, int> eventos;
    map<string, int> ips;

    NodeD<Log>* actual = lista.getNode(0);

    while (actual != nullptr) {
        Log log = actual->data;

        string fecha = log.mes + " " +
                       to_string(log.dia) + " " +
                       to_string(log.anio);

        dias[fecha]++;
        eventos[log.descripcion]++;
        ips[log.ip]++;

        actual = actual->next;
    }

    cout << "\nESTADISTICAS DEL ARCHIVO" << endl;
    cout << "Total de registros: " << lista.getSize() << endl;

    if (lista.getSize() == 0) {
        cout << "No hay suficientes registros para calcular las estadisticas"
             << endl;
        return;
    }

    cout << "\nDia con mas incidentes:" << endl;
    mostrarMayor(dias);

    cout << "\nTipo de evento mas frecuente:" << endl;
    mostrarMayor(eventos);

    cout << "\nIP que aparece mas veces:" << endl;
    mostrarMayor(ips);
}

int main() {

    Queue<LineaLog> fila;
    DoublyLinkedList<Log> listaLogs;

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

            listaLogs.addLast(log);

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
    cout << "Registros en lista doble: "
         << listaLogs.getSize() << endl;

    bool ordenada = false;
    bool busquedaRealizada = false;

    Log ultimaFecha;

    // Menu principal
    int opcionMenu = 0;

    do {
        cout << "\nMENU PRINCIPAL" << endl;
        cout << "1. Ordenar por fecha y hora" << endl;
        cout << "2. Buscar logs por dia" << endl;
        cout << "3. Mostrar logs por dia en orden descendente" << endl;
        cout << "4. Estadisticas del archivo" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion: ";

        if (!(cin >> opcionMenu)) {
            cout << "Opcion invalida" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (opcionMenu) {
            case 1:
                if (ordenarLogs(listaLogs, nombreArchivo, ordenada)) {
                    ordenada = true;
                }
                break;

            case 2:
                buscarDia(listaLogs, ordenada,
                          ultimaFecha, busquedaRealizada);
                break;

            case 3:
                mostrarDescendente(listaLogs, ordenada,
                                   ultimaFecha, busquedaRealizada);
                break;

            case 4:
                mostrarEstadisticas(listaLogs);
                break;

            case 5:
                cout << "Saliendo del programa" << endl;
                break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    } while (opcionMenu != 5);

    return 0;
}




