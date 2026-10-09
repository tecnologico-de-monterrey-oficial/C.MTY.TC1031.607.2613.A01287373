
// Caro Vildósola A01287373

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "DoublyLinkedList.h"

using namespace std;


// funcion para crear datos aleatorios
template <typename T>
T randomData();

template <>
int randomData<int>() {
    return rand() % 100 + 1;
}

template <>
string randomData<string>() {
    string nombres[] = {"Ana", "Luis", "Sofia", "Pedro", "Maria"};
    return nombres[rand() % 5];
}


// funcion para crear y manejar la lista
template <typename T>
void menuLista() {
    DoublyLinkedList<T> lista;
    DoublyLinkedList<T> otraLista;

    int opcion;
    int tipo;
    int cantidad;
    int index;
    T dato;
    T nuevoDato;

    // preguntamos como quiere crear la lista
    cout << "\nComo quieres crear la lista?" << endl;
    cout << "1. Datos capturados" << endl;
    cout << "2. Datos aleatorios" << endl;
    cout << "Opcion: ";
    cin >> tipo;

    // pedimos la cantidad de elementos
    cout << "Cuantos elementos quieres agregar? ";
    cin >> cantidad;

    // validamos la cantidad
    if (cantidad < 0) {
        cout << "Cantidad invalida" << endl;
        return;
    }

    // agregamos los elementos
    for (int i = 0; i < cantidad; i++) {
        if (tipo == 1) {
            cout << "Dato " << i + 1 << ": ";
            cin >> dato;
        } else if (tipo == 2) {
            dato = randomData<T>();
        } else {
            cout << "Opcion invalida" << endl;
            return;
        }

        lista.addLast(dato);
    }

    cout << "\nLista creada: ";
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

        cout << "Opcion: ";
        cin >> opcion;

        // usamos try para manejar indices invalidos
        try {
            switch (opcion) {

                case 1:
                    // agregamos al principio
                    cout << "Dato a agregar: ";
                    cin >> dato;
                    lista.addFirst(dato);
                    cout << "Dato agregado" << endl;
                    break;

                case 2:
                    // agregamos al final
                    cout << "Dato a agregar: ";
                    cin >> dato;
                    lista.addLast(dato);
                    cout << "Dato agregado" << endl;
                    break;

                case 3:
                    // insertamos despues de un indice
                    cout << "Indice: ";
                    cin >> index;
                    cout << "Dato a insertar: ";
                    cin >> dato;
                    lista.insert(index, dato);
                    cout << "Dato insertado" << endl;
                    break;

                case 4:
                    // borramos un dato
                    cout << "Dato a borrar: ";
                    cin >> dato;

                    if (lista.deleteData(dato)) {
                        cout << "Dato borrado" << endl;
                    } else {
                        cout << "No se encontro el dato" << endl;
                    }
                    break;

                case 5:
                    // borramos por posicion
                    cout << "Indice a borrar: ";
                    cin >> index;

                    if (lista.deleteAt(index)) {
                        cout << "Dato borrado" << endl;
                    } else {
                        cout << "Indice invalido" << endl;
                    }
                    break;

                case 6:
                    // obtenemos un dato
                    cout << "Indice: ";
                    cin >> index;
                    cout << "Dato: " << lista.getData(index) << endl;
                    break;

                case 7:
                    // actualizamos un dato
                    cout << "Dato a buscar: ";
                    cin >> dato;
                    cout << "Nuevo dato: ";
                    cin >> nuevoDato;
                    lista.updateData(dato, nuevoDato);
                    cout << "Dato actualizado" << endl;
                    break;

                case 8:
                    // actualizamos por posicion
                    cout << "Indice: ";
                    cin >> index;
                    cout << "Nuevo dato: ";
                    cin >> nuevoDato;
                    lista.updateAt(index, nuevoDato);
                    cout << "Dato actualizado" << endl;
                    break;

                case 9:
                    // buscamos un dato
                    cout << "Dato a buscar: ";
                    cin >> dato;

                    index = lista.findData(dato);

                    if (index == -1) {
                        cout << "No se encontro el dato" << endl;
                    } else {
                        cout << "Se encontro en el indice: " << index << endl;
                    }
                    break;

                case 10:
                    // leemos usando []
                    cout << "Indice: ";
                    cin >> index;
                    cout << "Dato: " << lista[index] << endl;
                    break;

                case 11:
                    // actualizamos usando []
                    cout << "Indice: ";
                    cin >> index;
                    cout << "Nuevo dato: ";
                    cin >> nuevoDato;
                    lista[index] = nuevoDato;
                    cout << "Dato actualizado" << endl;
                    break;

                case 12:
                    // copiamos la lista usando =
                    otraLista = lista;

                    cout << "Lista copiada: ";
                    otraLista.print();
                    break;

                case 13:
                    // limpiamos la lista
                    lista.clear();
                    cout << "Lista vacia" << endl;
                    break;

                case 14:
                    // ordenamos la lista
                    lista.sort();
                    cout << "Lista ordenada" << endl;
                    break;

                case 15:
                    // duplicamos cada elemento
                    lista.duplicate();
                    cout << "Elementos duplicados" << endl;
                    break;

                case 16:
                    // eliminamos los duplicados
                    lista.removeDuplicates();
                    cout << "Duplicados eliminados" << endl;
                    break;

                case 17:
                    // mostramos la lista
                    cout << "Lista: ";
                    lista.print();
                    cout << "Cantidad de elementos: " << lista.getSize() << endl;
                    break;

                case 18:
                    cout << "Saliendo del menu..." << endl;
                    break;

                default:
                    cout << "Opcion invalida" << endl;
            }

            // mostramos la lista despues de cada operacion
            if (opcion >= 1 && opcion <= 16 && opcion != 12) {
                cout << "Lista actual: ";
                lista.print();
            }

        } catch (out_of_range& error) {
            cout << "Error: " << error.what() << endl;
        }

    } while (opcion != 18);
}


// funcion principal
int main() {
    srand(time(0));

    int opcion;

    do {
        cout << "\n----- DOUBLY LINKED LIST -----" << endl;
        cout << "1. Lista de enteros" << endl;
        cout << "2. Lista de strings" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuLista<int>();
                break;

            case 2:
                menuLista<string>();
                break;

            case 3:
                cout << "Programa terminado" << endl;
                break;

            default:
                cout << "Opcion invalida" << endl;
        }

    } while (opcion != 3);

    return 0;
}