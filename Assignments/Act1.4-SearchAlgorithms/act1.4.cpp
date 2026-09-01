// Carolina Vildósola Guzmán
// A01287373

//programa 1

#include <iostream>   // cin y cout
#include <vector>     // vector
#include <algorithm>  // sort
#include <cstdlib>    // rand y srand
#include <ctime>      // time(0)
#include <chrono>     // medir tiempos

using namespace std;

/*
int main() {
    vector<int> numeros = {3,5,6,7,11,12,13,16,27,35};

    int buscar = 14;
    int left = 0;
    int right = numeros.size() - 1;
    int mid;

    mid = (left + right) /2;

    if (buscar > numeros[mid]) {
        left = mid + 1;
    }
    return 0;
}
*/


template <typename T>
int sequentialSearch(vector<T> &list, T data) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }

    return -1;
}

template <typename T>
int binarySearch(vector<T> &list, T data) {

    int left = 0;
    int right = list.size() - 1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (data == list[mid]) {
            return mid;
        }

        if (data < list[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {

    vector<int> numeros;

    srand(time(0));

    // generamos 10,000 numeros aleatorios
    for (int i = 0; i < 10000; i++) {
        int numero = rand() % 1000000 + 1;
        numeros.push_back(numero);
    }

    // ordenamos el vector
    sort(numeros.begin(), numeros.end());

    //para saber q número si exiten jeje
    cout << "Ejemplos de numeros que estan en la lista: " << endl;

for (int i = 0; i < 5; i++) {
    cout << numeros[i] << " ";
}

cout << endl;

    int buscar;

    cout << "Ingresa un numero entre 1 y 1000000 (0 para salir): ";
    cin >> buscar;

    while (buscar != 0) {

        // secuencial
        auto inicio = chrono::high_resolution_clock::now();

        int resultadoSecuencial = sequentialSearch(numeros, buscar);

        auto fin = chrono::high_resolution_clock::now();

        if (resultadoSecuencial != -1) {
            cout << "Secuencial: el numero si esta en la lista." << endl;
        } else {
            cout << "Secuencial: el numero no esta en la lista." << endl;
        }

        cout << "Tiempo secuencial: "
             << chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count()
             << " nanosegundos" << endl;


        // binaria
        auto inicio2 = chrono::high_resolution_clock::now();

        int resultadoBinario = binarySearch(numeros, buscar);

        auto fin2 = chrono::high_resolution_clock::now();

        if (resultadoBinario != -1) {
            cout << "Binaria: el numero si esta en la lista." << endl;
        } else {
            cout << "Binaria: el numero no esta en la lista." << endl;
        }

        cout << "Tiempo binario: "
             << chrono::duration_cast<chrono::nanoseconds>(fin2 - inicio2).count()
             << " nanosegundos" << endl;


        cout << "\nIngresa otro numero (0 para salir): ";
        cin >> buscar;
    }

    return 0;
}



