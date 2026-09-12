// Carolina Vidósola Guzmán
// A01287373

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

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
void swapSort(vector<T> &list, long long &comparaciones, long long &intercambios) {

    int n = list.size();

    comparaciones = 0;
    intercambios = 0;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            comparaciones++;

            if (list[i] > list[j]) {
                swap(list, i, j);
                intercambios++;
            }
        }
    }
}


// bubble sort
template <typename T>
void bubbleSort(vector<T> &list, long long &comparaciones, long long &intercambios) {

    int n = list.size();

    comparaciones = 0;
    intercambios = 0;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            comparaciones++;

            if (list[j] > list[j + 1]) {
                swap(list, j, j + 1);
                intercambios++;
            }
        }
    }
}


// selection sort
template <typename T>
void selectionSort(vector<T> &list, long long &comparaciones, long long &intercambios) {

    comparaciones = 0;
    intercambios = 0;

    // iteramos toda la lista desde el primer elemento hasta el penúltimo
    for (int i = 0; i < list.size() - 1; i++) {

        // hacemos indice de la posicion i como el mas chico
        int min = i;

        // iteramos desde el siguiente indice hasta el final
        for (int j = i + 1; j < list.size(); j++) {

            // comparamos el valor de j contra min
            comparaciones++;

            if (list[j] < list[min]) {

                // actualizamos el valor de min
                min = j;
            }
        }

        // intercambiamos min por i
        if (min != i) {
            swap(list, min, i);
            intercambios++;
        }
    }
}


// insertion sort
template <typename T>
void insertionSort(vector<T> &list, long long &comparaciones, long long &intercambios) {

    int n = list.size(); // cuantos elementos hay en la lista

    comparaciones = 0;
    intercambios = 0;

    for (int i = 1; i < n; i++) {

        // guarda en key el valor que esta en pos i
        T key = list[i];

        // j empieza en el numero de la izquierda de key
        int j = i - 1;

        // revisamos hacia la izquierda
        while (j >= 0) {

            comparaciones++;

            // si el numero de la izquierda es mayor que key
            if (list[j] > key) {

                // lo movemos una posicion a la derecha
                list[j + 1] = list[j];
                intercambios++;

                // nos movemos hacia la izquierda
                j--;

            } else {
                break;
            }
        }

        // colocamos key en el hueco que quedo
        list[j + 1] = key;
    }
}


// quick sort
// variables index, aux y pivot

template <typename T>
int getPivot(vector<T> &list, int left, int right) {

    T pivot = list[right]; // tomamos el ultimo elemento como pivote
    int index = left;      // posicion donde vamos poniendo los menores al pivote

    for (int i = left; i < right; i++) {

        // si el num es menor que el pivote, lo movemos a la izq
        if (list[i] < pivot) {

            swap(list, i, index);
            index++;
        }
    }

    // ponemos el pivote en su lugar correcto
    swap(list, index, right);

    return index; // regresamos la pos donde quedo el pivote
}


template <typename T>
void quickSort(vector<T> &list, int left, int right) {

    // solo seguimos si aun hay elementos que ordenar
    if (left < right) {

        // encontramos y acomodamos el pivote
        int pivot = getPivot(list, left, right);

        // ordenamos la parte izq
        quickSort(list, left, pivot - 1);

        // ordenamos la parte derecha
        quickSort(list, pivot + 1, right);
    }
}


// merge sort - en clase

template <typename T>
void merge(vector<T> &list, int left, int mid, int right) {

    // creamos una lista para los valores del lado izquierdo
    vector<T> leftList;

    // iteramos desde left hasta mid
    for (int i = left; i <= mid; i++) {
        leftList.push_back(list[i]);
    }

    // creamos una lista para los valores del lado derecho
    vector<T> rightList;

    // iteramos desde mid + 1 hasta right
    for (int i = mid + 1; i <= right; i++) {
        rightList.push_back(list[i]);
    }

    // indice que vamos a actualizar en la lista original
    int index = left;

    // indices de las dos listas
    int i = 0;
    int j = 0;

    // iteramos mientras no se acaben las listas
    while (i < leftList.size() && j < rightList.size()) {

        // comparamos izquierda con derecha
        if (leftList[i] < rightList[j]) {

            list[index] = leftList[i];
            i++;

        } else {

            list[index] = rightList[j];
            j++;
        }

        index++;
    }

    // vaciamos lo que falte de la lista izquierda
    while (i < leftList.size()) {

        list[index] = leftList[i];
        i++;
        index++;
    }

    // vaciamos lo que falte de la lista derecha
    while (j < rightList.size()) {

        list[index] = rightList[j];
        j++;
        index++;
    }
}


template <typename T>
void mergeSort(vector<T> &list, int left, int right) {

    // la condicion de control es que left < right
    if (left < right) {

        // calculamos mid
        int mid = left + (right - left) / 2;

        // ordenamos de left a mid
        mergeSort(list, left, mid);

        // ordenamos de mid + 1 a right
        mergeSort(list, mid + 1, right);

        // combinamos las dos partes
        merge(list, left, mid, right);
    }
}


// shell sort - algoritmo extra
template <typename T>
void shellSort(vector<T> &list) {

    int n = list.size();

    // empezamos con una separacion de la mitad de la lista
    for (int gap = n / 2; gap > 0; gap = gap / 2) {

        for (int i = gap; i < n; i++) {

            T temp = list[i];
            int j = i;

            // recorremos los numeros mayores
            while (j >= gap && list[j - gap] > temp) {

                list[j] = list[j - gap];
                j = j - gap;
            }

            list[j] = temp;
        }
    }
}


// crear lista aleatoria de int
vector<int> crearListaInt(int cantidad) {

    vector<int> list;

    for (int i = 0; i < cantidad; i++) {

        int numero = rand() % 100000 + 1;
        list.push_back(numero);
    }

    return list;
}


// crear lista aleatoria de double
vector<double> crearListaDouble(int cantidad) {

    vector<double> list;

    for (int i = 0; i < cantidad; i++) {

        // dividimos entre 100 para tener decimales
        double numero = (rand() % 10000000 + 1) / 100.0;
        list.push_back(numero);
    }

    return list;
}


// crear lista aleatoria de char
vector<char> crearListaChar(int cantidad) {

    vector<char> list;

    for (int i = 0; i < cantidad; i++) {

        // letra aleatoria entre A y Z
        char letra = 'A' + rand() % 26;
        list.push_back(letra);
    }

    return list;
}


// imprimir lista
template <typename T>
void imprimirLista(vector<T> &list) {

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    cout << endl;
}


// medir el tiempo de un algoritmo
template <typename T>
long long medirTiempo(vector<T> list, int algoritmo) {

    long long comparaciones = 0;
    long long intercambios = 0;

    auto inicio = chrono::high_resolution_clock::now();

    if (algoritmo == 1) {
        swapSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 2) {
        bubbleSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 3) {
        selectionSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 4) {
        insertionSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 5) {
        mergeSort(list, 0, list.size() - 1);
    }

    else if (algoritmo == 6) {
        quickSort(list, 0, list.size() - 1);
    }

    else if (algoritmo == 7) {
        shellSort(list);
    }

    auto fin = chrono::high_resolution_clock::now();

    long long tiempo =
        chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

    return tiempo;
}


// ejecutar el algoritmo escogido
template <typename T>
void ejecutarAlgoritmo(vector<T> list, int algoritmo) {

    long long comparaciones = 0;
    long long intercambios = 0;

    auto inicio = chrono::high_resolution_clock::now();

    if (algoritmo == 1) {
        swapSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 2) {
        bubbleSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 3) {
        selectionSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 4) {
        insertionSort(list, comparaciones, intercambios);
    }

    else if (algoritmo == 5) {
        mergeSort(list, 0, list.size() - 1);
    }

    else if (algoritmo == 6) {
        quickSort(list, 0, list.size() - 1);
    }

    else if (algoritmo == 7) {
        shellSort(list);
    }

    auto fin = chrono::high_resolution_clock::now();

    long long tiempo =
        chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

    cout << endl;

    cout << "Lista ordenada:" << endl;
    imprimirLista(list);

    cout << endl;

    cout << "Tiempo: "
         << tiempo
         << " nanosegundos"
         << endl;

    // para los primeros 4 mostramos comparaciones e intercambios
    if (algoritmo >= 1 && algoritmo <= 4) {

        cout << "Comparaciones: "
             << comparaciones
             << endl;

        cout << "Intercambios: "
             << intercambios
             << endl;
    }
}


// comparar los tres tamaños
template <typename T>
void compararTiempos(
    vector<T> list1000,
    vector<T> list10000,
    vector<T> list100000,
    string tipo) {

    cout << endl;

    cout << "algoritmo, tipo de dato, tiempo1000, tiempo10000, tiempo100000"
         << endl;

    string nombres[7] = {
        "swapSort",
        "bubbleSort",
        "selectionSort",
        "insertionSort",
        "mergeSort",
        "quickSort",
        "shellSort"
    };

    for (int i = 1; i <= 7; i++) {

        cout << nombres[i - 1] << ", "
             << tipo << ", "
             << medirTiempo(list1000, i) << ", "
             << medirTiempo(list10000, i) << ", "
             << medirTiempo(list100000, i)
             << endl;
    }
}



int main() {

    srand(time(0));


    // listas de int
    vector<int> int1000;
    vector<int> int10000;
    vector<int> int100000;


    // listas de double
    vector<double> double1000;
    vector<double> double10000;
    vector<double> double100000;


    // listas de char
    vector<char> char1000;
    vector<char> char10000;
    vector<char> char100000;


    bool listasCreadas = false;

    int opcion = -1;


    while (opcion != 0) {

        cout << endl;
        cout << "ALGORITMOS MENU" << endl;
        cout << "1. Crear listas aleatorias" << endl;
        cout << "2. Swap Sort" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Merge Sort" << endl;
        cout << "7. Quick Sort" << endl;
        cout << "8. Shell Sort" << endl;
        cout << "9. Comparar tiempos" << endl;
        cout << "0. Salir" << endl;

        cout << "Opcion: ";
        cin >> opcion;


        // crear las listas aleatorias
        if (opcion == 1) {

            int1000 = crearListaInt(1000);
            int10000 = crearListaInt(10000);
            int100000 = crearListaInt(100000);

            double1000 = crearListaDouble(1000);
            double10000 = crearListaDouble(10000);
            double100000 = crearListaDouble(100000);

            char1000 = crearListaChar(1000);
            char10000 = crearListaChar(10000);
            char100000 = crearListaChar(100000);

            listasCreadas = true;

            cout << endl;
            cout << "Listas creadas correctamente." << endl;
        }


        // opciones de algoritmos
        else if (opcion >= 2 && opcion <= 8) {

            if (listasCreadas == false) {

                cout << "Primero debes crear las listas." << endl;

            } else {

                int tipo;
                int cantidad;

                cout << endl;
                cout << "Tipo de dato:" << endl;
                cout << "1. int" << endl;
                cout << "2. double" << endl;
                cout << "3. char" << endl;
                cout << "Opcion: ";
                cin >> tipo;


                cout << endl;
                cout << "Cantidad de datos:" << endl;
                cout << "1. 1000" << endl;
                cout << "2. 10000" << endl;
                cout << "3. 100000" << endl;
                cout << "Opcion: ";
                cin >> cantidad;


                // el menu empieza los algoritmos en 2
                int algoritmo = opcion - 1;


                // int
                if (tipo == 1) {

                    if (cantidad == 1) {
                        ejecutarAlgoritmo(int1000, algoritmo);
                    }

                    else if (cantidad == 2) {
                        ejecutarAlgoritmo(int10000, algoritmo);
                    }

                    else if (cantidad == 3) {
                        ejecutarAlgoritmo(int100000, algoritmo);
                    }

                    else {
                        cout << "Cantidad no valida." << endl;
                    }
                }


                // double
                else if (tipo == 2) {

                    if (cantidad == 1) {
                        ejecutarAlgoritmo(double1000, algoritmo);
                    }

                    else if (cantidad == 2) {
                        ejecutarAlgoritmo(double10000, algoritmo);
                    }

                    else if (cantidad == 3) {
                        ejecutarAlgoritmo(double100000, algoritmo);
                    }

                    else {
                        cout << "Cantidad no valida." << endl;
                    }
                }


                // char
                else if (tipo == 3) {

                    if (cantidad == 1) {
                        ejecutarAlgoritmo(char1000, algoritmo);
                    }

                    else if (cantidad == 2) {
                        ejecutarAlgoritmo(char10000, algoritmo);
                    }

                    else if (cantidad == 3) {
                        ejecutarAlgoritmo(char100000, algoritmo);
                    }

                    else {
                        cout << "Cantidad no valida." << endl;
                    }
                }


                else {
                    cout << "Tipo de dato no valido." << endl;
                }
            }
        }


        // comparar todos los tiempos
        else if (opcion == 9) {

            if (listasCreadas == false) {

                cout << "Primero debes crear las listas." << endl;

            } else {

                cout << endl;
                cout << "INT" << endl;

                compararTiempos(
                    int1000,
                    int10000,
                    int100000,
                    "int"
                );


                cout << endl;
                cout << "DOUBLE" << endl;

                compararTiempos(
                    double1000,
                    double10000,
                    double100000,
                    "double"
                );


                cout << endl;
                cout << "CHAR" << endl;

                compararTiempos(
                    char1000,
                    char10000,
                    char100000,
                    "char"
                );
            }
        }


        else if (opcion == 0) {

            cout << "Programa terminado." << endl;

        }


        else {

            cout << "Opcion no valida." << endl;
        }
    }


    return 0;
}


// fin!!