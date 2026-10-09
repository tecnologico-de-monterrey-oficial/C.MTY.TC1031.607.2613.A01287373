// Caro Vildósola A01287373

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "DoublyLinkedList.h"

using namespace std;


// randomData

template <typename T>
T randomData();

template <>
int randomData<int>() {
    // generamos un numero del 1 al 100
    return rand() % 100 + 1;
}

template <>
string randomData<string>() {
    // usamos estos nombres para los datos aleatorios
    string nombres[] = {"Caro", "David", "Dani", "Alonso", "Vale"};
    return nombres[rand() % 5];
}


// menuLista

template <typename T>
void menuLista() {
    // creamos nuestras listas
    DoublyLinkedList<T> lista;
    DoublyLinkedList<T> otraLista;

    int opcion;
    int tipo;
    int cantidad;
    int index;
    T dato;
    T nuevoDato;

    // preguntamos como quiere agregar los datos
    cout << "\nComo quieres agregar los datos?" << endl;
    cout << "1. Escribirlos yo" << endl;
    cout << "2. Que se generen solos" << endl;
    cout << "Elige una opcion: ";
    cin >> tipo;

    // revisamos que la opcion sea valida
    if (tipo != 1 && tipo != 2) {
        cout << "Esa opcion no existe" << endl;
        return;
    }

    // preguntamos cuantos datos quiere
    cout << "Cuantos datos quieres poner? ";
    cin >> cantidad;

    // revisamos que la cantidad sea valida
    if (cantidad < 0) {
        cout << "Cantidad invalida" << endl;
        return;
    }

    // agregamos los datos a la lista
    for (int i = 0; i < cantidad; i++) {
        if (tipo == 1) {
            // pedimos el dato
            cout << "Dato " << i + 1 << ": ";
            cin >> dato;
        } else {
            // generamos un dato aleatorio
            dato = randomData<T>();
        }

        // agregamos el dato al final
        lista.addLast(dato);
    }

    cout << "\nAsi quedo tu lista: ";
    lista.print();

    // mostramos el menu
    do {
        cout << "\n----- MENU DOUBLY LINKED LIST -----" << endl;
        cout << "1. Agregar al principio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar despues de un indice" << endl;
        cout << "4. Borrar un dato" << endl;
        cout << "5. Borrar por posicion" << endl;
        cout << "6. Obtener dato por posicion" << endl;
        cout << "7. Actualizar un dato" << endl;
        cout << "8. Actualizar por posicion" << endl;
        cout << "9. Buscar un dato" << endl;
        cout << "10. Leer con operador []" << endl;
        cout << "11. Actualizar con operador []" << endl;
        cout << "12. Copiar lista con operador =" << endl;
        cout << "13. Limpiar lista" << endl;
        cout << "14. Ordenar lista" << endl;
        cout << "15. Duplicar elementos" << endl;
        cout << "16. Eliminar duplicados" << endl;
        cout << "17. Mostrar lista" << endl;
        cout << "18. Salir" << endl;

        cout << "Elige una opcion: ";
        cin >> opcion;

        // usamos try por si hay un indice invalido
        try {
            switch (opcion) {

                case 1:
                    // addFirst
                    cout << "Que dato quieres agregar? ";
                    cin >> dato;
                    lista.addFirst(dato);
                    cout << "Listo, se agrego el dato" << endl;
                    break;

                case 2:
                    // addLast
                    cout << "Que dato quieres agregar? ";
                    cin >> dato;
                    lista.addLast(dato);
                    cout << "Listo, se agrego el dato" << endl;
                    break;

                case 3:
                    // insert
                    cout << "Despues de que indice quieres agregarlo? ";
                    cin >> index;
                    cout << "Que dato quieres insertar? ";
                    cin >> dato;
                    lista.insert(index, dato);
                    cout << "Listo, se inserto el dato" << endl;
                    break;

                case 4:
                    // deleteData
                    cout << "Que dato quieres borrar? ";
                    cin >> dato;

                    if (lista.deleteData(dato)) {
                        cout << "Listo, se borro el dato" << endl;
                    } else {
                        cout << "Ese dato no esta en la lista" << endl;
                    }
                    break;

                case 5:
                    // deleteAt
                    cout << "En que posicion quieres borrar? ";
                    cin >> index;

                    if (lista.deleteAt(index)) {
                        cout << "Listo, se borro el dato" << endl;
                    } else {
                        cout << "Esa posicion no existe" << endl;
                    }
                    break;

                case 6:
                    // getData
                    cout << "De que posicion quieres ver el dato? ";
                    cin >> index;
                    cout << "El dato es: " << lista.getData(index) << endl;
                    break;

                case 7:
                    // updateData
                    cout << "Que dato quieres cambiar? ";
                    cin >> dato;
                    cout << "Por que dato lo quieres cambiar? ";
                    cin >> nuevoDato;

                    lista.updateData(dato, nuevoDato);
                    cout << "Listo, se cambio el dato" << endl;
                    break;

                case 8:
                    // updateAt
                    cout << "En que posicion quieres cambiar el dato? ";
                    cin >> index;
                    cout << "Por que dato lo quieres cambiar? ";
                    cin >> nuevoDato;

                    lista.updateAt(index, nuevoDato);
                    cout << "Listo, se cambio el dato" << endl;
                    break;

                case 9:
                    // findData
                    cout << "Que dato quieres buscar? ";
                    cin >> dato;

                    index = lista.findData(dato);

                    if (index == -1) {
                        cout << "Ese dato no esta en la lista" << endl;
                    } else {
                        cout << "Esta en el indice: " << index << endl;
                    }
                    break;

                case 10:
                    // operator[]
                    cout << "De que posicion quieres ver el dato? ";
                    cin >> index;
                    cout << "El dato es: " << lista[index] << endl;
                    break;

                case 11:
                    // operator[]
                    cout << "En que posicion quieres cambiar el dato? ";
                    cin >> index;
                    cout << "Por que dato lo quieres cambiar? ";
                    cin >> nuevoDato;

                    lista[index] = nuevoDato;
                    cout << "Listo, se cambio el dato" << endl;
                    break;

                case 12:
                    // operator=
                    // copiamos los datos a otra lista
                    otraLista = lista;

                    cout << "Asi quedo la lista copiada: ";
                    otraLista.print();
                    break;

                case 13:
                    // clear
                    lista.clear();
                    cout << "Listo, la lista esta vacia" << endl;
                    break;

                case 14:
                    // sort
                    lista.sort();
                    cout << "Listo, se ordeno la lista" << endl;
                    break;

                case 15:
                    // duplicate
                    lista.duplicate();
                    cout << "Listo, se duplicaron los datos" << endl;
                    break;

                case 16:
                    // removeDuplicates
                    lista.removeDuplicates();
                    cout << "Listo, se quitaron los repetidos" << endl;
                    break;

                case 17:
                    // print
                    cout << "Tu lista es: ";
                    lista.print();
                    cout << "Tiene " << lista.getSize() << " elementos" << endl;
                    break;

                case 18:
                    cout << "Saliendo del menu..." << endl;
                    break;

                default:
                    cout << "Esa opcion no existe" << endl;
            }

            // mostramos como quedo la lista
            if (opcion >= 1 && opcion <= 16 && opcion != 12) {
                cout << "Asi quedo la lista: ";
                lista.print();
            }

        } catch (out_of_range& error) {
            // mostramos el error si la posicion no existe
            cout << "Error: " << error.what() << endl;
        }

    } while (opcion != 18);
}


// main

int main() {
    // iniciamos los numeros aleatorios
    srand(time(0));

    int opcion;

    do {
        cout << "\n DOUBLY LINKED LIST " << endl;
        cout << "1. Lista de enteros" << endl;
        cout << "2. Lista de strings" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // creamos una lista de numeros
                menuLista<int>();
                break;

            case 2:
                // creamos una lista de palabras
                menuLista<string>();
                break;

            case 3:
                cout << "Programa terminado" << endl;
                break;

            default:
                cout << "Esa opcion no existe" << endl;
        }

    } while (opcion != 3);

    return 0;
}