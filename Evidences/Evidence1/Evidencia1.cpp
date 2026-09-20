

// Carolina Vildosola Guzman
// A01287373

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Un log es un registro de algo que paso en el sistema
// Cada linea guarda la fecha, hora, IP y lo que paso
struct Log {
    string mes;
    int dia;
    int anio;
    string hora;
    string ip;
    string mensaje;
};


// Se convierte el mes de letras a numero
int mesANumero(string mes) {
    if (mes == "Jan") return 1;
    if (mes == "Feb") return 2;
    if (mes == "Mar") return 3;
    if (mes == "Apr") return 4;
    if (mes == "May") return 5;
    if (mes == "Jun") return 6;
    if (mes == "Jul") return 7;
    if (mes == "Aug") return 8;
    if (mes == "Sep") return 9;
    if (mes == "Oct") return 10;
    if (mes == "Nov") return 11;
    if (mes == "Dec") return 12;

    return 0;
}


// Compara dos logs para saber cual paso primero
bool esMenor(Log a, Log b) {

    if (a.anio != b.anio) {
        return a.anio < b.anio;
    }

    if (mesANumero(a.mes) != mesANumero(b.mes)) {
        return mesANumero(a.mes) < mesANumero(b.mes);
    }

    if (a.dia != b.dia) {
        return a.dia < b.dia;
    }

    return a.hora < b.hora;
}


// Intercambia dos logs
void swapLogs(vector<Log> &list, int i, int j) {
    if (i != j) {
        Log aux = list[i];
        list[i] = list[j];
        list[j] = aux;
    }
}


// SWAP SORT
void swapSort(vector<Log> &list) {

    int n = list.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (esMenor(list[j], list[i])) {
                swapLogs(list, i, j);
            }
        }
    }
}


// BUBBLE SORT
void bubbleSort(vector<Log> &list) {

    int n = list.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (esMenor(list[j + 1], list[j])) {
                swapLogs(list, j, j + 1);
            }
        }
    }
}


// SELECTION SORT
void selectionSort(vector<Log> &list) {

    for (int i = 0; i < list.size() - 1; i++) {

        int min = i;

        for (int j = i + 1; j < list.size(); j++) {

            if (esMenor(list[j], list[min])) {
                min = j;
            }
        }

        if (min != i) {
            swapLogs(list, min, i);
        }
    }
}


// INSERTION SORT
void insertionSort(vector<Log> &list) {

    int n = list.size();

    for (int i = 1; i < n; i++) {

        Log key = list[i];
        int j = i - 1;

        while (j >= 0 && esMenor(key, list[j])) {
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = key;
    }
}


// MERGE
void merge(vector<Log> &list, int left, int mid, int right) {

    vector<Log> leftList;
    vector<Log> rightList;

    for (int i = left; i <= mid; i++) {
        leftList.push_back(list[i]);
    }

    for (int i = mid + 1; i <= right; i++) {
        rightList.push_back(list[i]);
    }

    int index = left;
    int i = 0;
    int j = 0;

    while (i < leftList.size() && j < rightList.size()) {

        if (esMenor(leftList[i], rightList[j])) {
            list[index] = leftList[i];
            i++;
        }
        else {
            list[index] = rightList[j];
            j++;
        }

        index++;
    }

    while (i < leftList.size()) {
        list[index] = leftList[i];
        i++;
        index++;
    }

    while (j < rightList.size()) {
        list[index] = rightList[j];
        j++;
        index++;
    }
}


// MERGE SORT
void mergeSort(vector<Log> &list, int left, int right) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);

        merge(list, left, mid, right);
    }
}


// PIVOTE PARA QUICK SORT
int getPivot(vector<Log> &list, int left, int right) {

    Log pivot = list[right];
    int index = left;

    for (int i = left; i < right; i++) {

        if (esMenor(list[i], pivot)) {
            swapLogs(list, i, index);
            index++;
        }
    }

    swapLogs(list, index, right);

    return index;
}


// QUICK SORT
void quickSort(vector<Log> &list, int left, int right) {

    if (left < right) {

        int pivot = getPivot(list, left, right);

        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}


// SHELL SORT
void shellSort(vector<Log> &list) {

    int n = list.size();

    for (int gap = n / 2; gap > 0; gap = gap / 2) {

        for (int i = gap; i < n; i++) {

            Log temp = list[i];
            int j = i;

            while (j >= gap && esMenor(temp, list[j - gap])) {
                list[j] = list[j - gap];
                j = j - gap;
            }

            list[j] = temp;
        }
    }
}


// Muestra la complejidad del algoritmo elegido
void mostrarComplejidad(int opcion) {

    cout << "Complejidad teorica:" << endl;

    if (opcion == 1) {
        cout << "Swap Sort - Mejor: O(n^2) | Peor: O(n^2)" << endl;
    }
    else if (opcion == 2) {
        cout << "Bubble Sort - Mejor: O(n^2) | Peor: O(n^2)" << endl;
    }
    else if (opcion == 3) {
        cout << "Selection Sort - Mejor: O(n^2) | Peor: O(n^2)" << endl;
    }
    else if (opcion == 4) {
        cout << "Insertion Sort - Mejor: O(n) | Peor: O(n^2)" << endl;
    }
    else if (opcion == 5) {
        cout << "Merge Sort - Mejor: O(n log n) | Peor: O(n log n)" << endl;
    }
    else if (opcion == 6) {
        cout << "Quick Sort - Mejor: O(n log n) | Peor: O(n^2)" << endl;
    }
    else if (opcion == 7) {
        cout << "Shell Sort - Depende de la secuencia de gaps utilizada" << endl;
    }
}

// Guarda los logs ordenados en un archivo
void guardarLogs(vector<Log> &logs) {

    ofstream salida("output607.txt");

    if (!salida.is_open()) {
        cout << "Error al crear output607.txt" << endl;
        return;
    }

    for (int i = 0; i < logs.size(); i++) {

        salida << logs[i].mes << " "
               << logs[i].dia << " "
               << logs[i].anio << " "
               << logs[i].hora << " "
               << logs[i].ip
               << logs[i].mensaje << endl;
    }

    salida.close();

    cout << "Los logs ordenados se guardaron en output607.txt" << endl;
}


int main() {

    // ELEGIR ARCHIVO

    int opcionArchivo;
    string nombreArchivo;

    cout << "Elige el archivo:" << endl;
    cout << "1. log607-1.txt" << endl;
    cout << "2. log607-2.txt" << endl;
    cout << "Opcion: ";
    cin >> opcionArchivo;

    if (opcionArchivo == 1) {
        nombreArchivo = "data/log607-1.txt";
    }
    else if (opcionArchivo == 2) {
        nombreArchivo = "data/log607-2.txt";
    }
    else {
        cout << "Opcion no valida." << endl;
        return 1;
    }


    // ABRIR Y LEER ARCH


    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return 1;
    }

    cout << "Archivo abierto correctamente." << endl;

    vector<Log> logs;
    Log registro;

    while (archivo >> registro.mes >> registro.dia >> registro.anio
                   >> registro.hora >> registro.ip) {

        getline(archivo, registro.mensaje);

        logs.push_back(registro);
    }

    archivo.close();

    cout << "Se leyeron " << logs.size() << " logs." << endl;



    // ELEGIR ALG


    int opcionAlgoritmo;

    cout << endl;
    cout << "Elige el algoritmo de ordenamiento:" << endl;
    cout << "1. Swap Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Insertion Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "7. Shell Sort" << endl;
    cout << "Opcion: ";

    cin >> opcionAlgoritmo;

    // PREDICCION


    string prediccion;

    cout << endl;
    cout << "Antes de ordenar, escribe tu prediccion." << endl;
    cout << "Crees que sera rapido o lento?: ";
    cin >> prediccion;

    cin.ignore();

    string razon;

    cout << "Por que?: ";
    getline(cin, razon);


    // MEDIR TIEMPO
  

    auto inicio = chrono::high_resolution_clock::now();


    // Ejecutamos el algoritmo elegido

    if (opcionAlgoritmo == 1) {
        swapSort(logs);
    }

    else if (opcionAlgoritmo == 2) {
        bubbleSort(logs);
    }

    else if (opcionAlgoritmo == 3) {
        selectionSort(logs);
    }

    else if (opcionAlgoritmo == 4) {
        insertionSort(logs);
    }

    else if (opcionAlgoritmo == 5) {
        mergeSort(logs, 0, logs.size() - 1);
    }

    else if (opcionAlgoritmo == 6) {
        quickSort(logs, 0, logs.size() - 1);
    }

    else if (opcionAlgoritmo == 7) {
        shellSort(logs);
    }

    else {
        cout << "Algoritmo no valido." << endl;
        return 1;
    }


    auto fin = chrono::high_resolution_clock::now();

    auto tiempo =
        chrono::duration_cast<chrono::nanoseconds>(fin - inicio);


     // Guardamos los logs ya ordenados
    guardarLogs(logs);

  
    // MOSTRAR RESULTADO
   

    cout << endl;
    cout << "Ordenamiento terminado." << endl;
    cout << "Cantidad de logs: " << logs.size() << endl;
    cout << "Tiempo: " << tiempo.count() << " nanosegundos" << endl;

    mostrarComplejidad(opcionAlgoritmo);

    cout << "Tu prediccion fue: " << prediccion << endl;
    cout << "Razon: " << razon << endl;


    return 0;
}