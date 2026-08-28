
 // Carolina Vildósola Guzmán
// A01287373

#include <iostream>
#include <vector>
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

//busqueda binaria

template <typename T>
int binarySearch(vector<T> &list, T data) {
   //obtenemos left
   int left = 0;
   //obtenemos right
    int right = list.size() - 1;
    // buscamos el elemento mientras left <= right

    while (left <= right) {
        //obtenemos la mitad
        int mid = (left + right) / 2;
        // comparamos valor buscado con valor de la mitad
        if (data == list[mid]) {
            //regresamos el valor de mid que es el indice del valor encontrado
            return mid;
        } else {
            //preguntamos si el valor buscado es menor que el valor de mid 
            if (data< list[mid]) {
                //si es menor, entonces el valor buscado se encuentra en la mitad izquierda
                right = mid - 1;
                        } else {
                //si es mayor, entonces el valor buscado se encuentra en la mitad derecha
                left = mid + 1;
            }
        }
    }

    throw out_of_range("El valor no se encuentra en la lista");
}
    

int main() {
    vector<int> numeros = {3,5,6,7,11,12,13,16,27,35};
    int buscar = 14;
    int resultado = binarySearch(numeros, buscar);
    try {
        if (resultado != -1) {
            cout << "El valor " << buscar << " se encuentra en el índice: " <<
        resultado << endl;
        }
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

}


