// Carolina Vidósola Guzmán
// A01287373

#include <iostream>
#include <vector>

using namespace std;

// función swap
template <typename T>
void swap(vector<T> &list, int i, int j) {
    if (i != j) {
        T aux = list[i];
        list[i] = list[j];
        list[j] = aux;
    }
}


// swap sort
template <typename T>
void swapSort(vector<T> &list) {
    int n = list.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (list[j] > list[j + 1]) {
                swap(list, j, j + 1);
            }
        }
    }
}


// bubble sort
template <typename T>
void bubbleSort(vector<T> &list) {
    int n = list.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (list[j] > list[j + 1]) {
                swap(list, j, j + 1);
            }
        }
    }
}


// selection sort
template <typename T>
void selectionSort(vector<T> &list) {

    // iteramos toda la lista desde el primer elemento hasta el penúltimo
    for (int i = 0; i < list.size() - 1; i++) {

        // hacemos indice de la posicion i como el mas chico
        int min = i;

        // iteramos desde el siguiente indice hasta el final
        for (int j = i + 1; j < list.size(); j++) {

            // comparamos el valor de j contra min
            if (list[j] < list[min]) {

                // actualizamos el valor de min
                min = j;
            }
        }

        // intercambiamos min por i
        swap(list, min, i);
    }
}


// insertion sort
template <typename T>
void insertionSort(vector<T> &list) {

    int n = list.size(); // cuantos elementos hay en la lista

    for (int i = 1; i < n; i++) {

        // guarda en key el valor que esta en pos i
        T key = list[i];

        // j empieza en el numero de la izquierda de key
        int j = i - 1;

        // mientras el numero de la izquierda sea mayor que key,
        // lo movemos una posicion a la derecha
        while (j >= 0 && list[j] > key) {

            list[j + 1] = list[j];

            // nos movemos hacia la izquierda
            j--;
        }

        // colocamos key en el hueco que quedo
        list[j + 1] = key;
    }
}


int main() {

    vector<double> list = {64, 34, 25, 12, 11.4, 11.6, 90};


    swapSort(list);

    cout << "Sorted swap: \n";

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    cout << endl;


    cout << "Sorted bubble: \n";

    bubbleSort(list);

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    cout << endl;


    cout << "Sorted insertion: \n";

    insertionSort(list);

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    cout << endl;


    cout << "Sorted selection: \n";

    selectionSort(list);

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    cout << endl;

    return 0;
}