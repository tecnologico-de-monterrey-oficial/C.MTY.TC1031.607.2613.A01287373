
// Carolina Vildósola Guzmán
// A01287373

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "LinkedList.h"


// menu para listas de enteros
void menuEnteros(LinkedList<int>& lista) {

    int opcion = 0;

    while (opcion != 12) {

        cout << "\nMENU" << endl;
        cout << "1. Agregar al principio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar despues de un indice" << endl;
        cout << "4. Borrar un dato" << endl;
        cout << "5. Borrar por posicion" << endl;
        cout << "6. Obtener dato por posicion" << endl;
        cout << "7. Actualizar un dato" << endl;
        cout << "8. Actualizar por posicion" << endl;
        cout << "9. Buscar un dato" << endl;
        cout << "10. Usar operador []" << endl;
        cout << "11. Probar operador =" << endl;
        cout << "12. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        int dato;
        int nuevoDato;
        int index;

        try {

            switch (opcion) {

                case 1:
                    cout << "Dato: ";
                    cin >> dato;
                    lista.push_front(dato);
                    lista.print();
                    break;

                case 2:
                    cout << "Dato: ";
                    cin >> dato;
                    lista.push_back(dato);
                    lista.print();
                    break;

                case 3:
                    cout << "Indice: ";
                    cin >> index;
                    cout << "Dato: ";
                    cin >> dato;
                    lista.insert(index, dato);
                    lista.print();
                    break;

                case 4:
                    cout << "Dato a borrar: ";
                    cin >> dato;

                    if (lista.deleteData(dato)) {
                        cout << "Dato borrado" << endl;
                    }
                    else {
                        cout << "Dato no encontrado" << endl;
                    }

                    lista.print();
                    break;

                case 5:
                    cout << "Posicion a borrar: ";
                    cin >> index;

                    if (lista.deleteAt(index)) {
                        cout << "Dato borrado" << endl;
                    }
                    else {
                        cout << "Posicion invalida" << endl;
                    }

                    lista.print();
                    break;

                case 6:
                    cout << "Posicion: ";
                    cin >> index;
                    cout << "Dato: " << lista.getData(index) << endl;
                    break;

                case 7:
                    cout << "Dato que quieres cambiar: ";
                    cin >> dato;
                    cout << "Nuevo dato: ";
                    cin >> nuevoDato;

                    lista.updateData(dato, nuevoDato);
                    lista.print();
                    break;

                case 8:
                    cout << "Posicion: ";
                    cin >> index;
                    cout << "Nuevo dato: ";
                    cin >> nuevoDato;

                    lista.updateAt(index, nuevoDato);
                    lista.print();
                    break;

                case 9:
                    cout << "Dato a buscar: ";
                    cin >> dato;

                    index = lista.findData(dato);

                    if (index == -1) {
                        cout << "Dato no encontrado" << endl;
                    }
                    else {
                        cout << "Dato encontrado en la posicion: "
                             << index << endl;
                    }
                    break;

                case 10:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato usando []: "
                         << lista[index] << endl;

                    cout << "Nuevo valor: ";
                    cin >> nuevoDato;

                    lista[index] = nuevoDato;
                    lista.print();
                    break;

                case 11: {
                    LinkedList<int> copia;
                    copia = lista;

                    cout << "Copia de la lista: ";
                    copia.print();
                    break;
                }

                case 12:
                    cout << "Fin del programa" << endl;
                    break;

                default:
                    cout << "Opcion invalida" << endl;
            }

        }
        catch (out_of_range& error) {
            cout << "Error: " << error.what() << endl;
        }
    }
}


// menu para listas de strings
void menuStrings(LinkedList<string>& lista) {

    int opcion = 0;

    while (opcion != 12) {

        cout << "\nMENU" << endl;
        cout << "1. Agregar al principio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar despues de un indice" << endl;
        cout << "4. Borrar un dato" << endl;
        cout << "5. Borrar por posicion" << endl;
        cout << "6. Obtener dato por posicion" << endl;
        cout << "7. Actualizar un dato" << endl;
        cout << "8. Actualizar por posicion" << endl;
        cout << "9. Buscar un dato" << endl;
        cout << "10. Usar operador []" << endl;
        cout << "11. Probar operador =" << endl;
        cout << "12. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        string dato;
        string nuevoDato;
        int index;

        try {

            switch (opcion) {

                case 1:
                    cout << "Dato: ";
                    cin >> dato;
                    lista.push_front(dato);
                    lista.print();
                    break;

                case 2:
                    cout << "Dato: ";
                    cin >> dato;
                    lista.push_back(dato);
                    lista.print();
                    break;

                case 3:
                    cout << "Indice: ";
                    cin >> index;
                    cout << "Dato: ";
                    cin >> dato;
                    lista.insert(index, dato);
                    lista.print();
                    break;

                case 4:
                    cout << "Dato a borrar: ";
                    cin >> dato;

                    if (lista.deleteData(dato)) {
                        cout << "Dato borrado" << endl;
                    }
                    else {
                        cout << "Dato no encontrado" << endl;
                    }

                    lista.print();
                    break;

                case 5:
                    cout << "Posicion a borrar: ";
                    cin >> index;

                    if (lista.deleteAt(index)) {
                        cout << "Dato borrado" << endl;
                    }
                    else {
                        cout << "Posicion invalida" << endl;
                    }

                    lista.print();
                    break;

                case 6:
                    cout << "Posicion: ";
                    cin >> index;
                    cout << "Dato: " << lista.getData(index) << endl;
                    break;

                case 7:
                    cout << "Dato que quieres cambiar: ";
                    cin >> dato;
                    cout << "Nuevo dato: ";
                    cin >> nuevoDato;

                    lista.updateData(dato, nuevoDato);
                    lista.print();
                    break;

                case 8:
                    cout << "Posicion: ";
                    cin >> index;
                    cout << "Nuevo dato: ";
                    cin >> nuevoDato;

                    lista.updateAt(index, nuevoDato);
                    lista.print();
                    break;

                case 9:
                    cout << "Dato a buscar: ";
                    cin >> dato;

                    index = lista.findData(dato);

                    if (index == -1) {
                        cout << "Dato no encontrado" << endl;
                    }
                    else {
                        cout << "Dato encontrado en la posicion: "
                             << index << endl;
                    }
                    break;

                case 10:
                    cout << "Posicion: ";
                    cin >> index;

                    cout << "Dato usando []: "
                         << lista[index] << endl;

                    cout << "Nuevo valor: ";
                    cin >> nuevoDato;

                    lista[index] = nuevoDato;
                    lista.print();
                    break;

                case 11: {
                    LinkedList<string> copia;
                    copia = lista;

                    cout << "Copia de la lista: ";
                    copia.print();
                    break;
                }

                case 12:
                    cout << "Fin del programa" << endl;
                    break;

                default:
                    cout << "Opcion invalida" << endl;
            }

        }
        catch (out_of_range& error) {
            cout << "Error: " << error.what() << endl;
        }
    }
}


int main() {

    int tipo;

    cout << "LISTA ENCADENADA" << endl;
    cout << "1. Lista de enteros" << endl;
    cout << "2. Lista de strings" << endl;
    cout << "Selecciona el tipo de lista: ";
    cin >> tipo;


    if (tipo == 1) {

        LinkedList<int> lista;

        int forma;
        int cantidad;

        cout << "1. Datos aleatorios" << endl;
        cout << "2. Datos capturados" << endl;
        cout << "Selecciona una opcion: ";
        cin >> forma;

        cout << "Cuantos elementos quieres agregar? ";
        cin >> cantidad;

        if (forma == 1) {

            for (int i = 0; i < cantidad; i++) {
                lista.push_back(rand() % 100);
            }

        }
        else if (forma == 2) {

            for (int i = 0; i < cantidad; i++) {

                int dato;

                cout << "Dato " << i + 1 << ": ";
                cin >> dato;

                lista.push_back(dato);
            }
        }

        cout << "Lista creada: ";
        lista.print();

        menuEnteros(lista);
    }


    else if (tipo == 2) {

        LinkedList<string> lista;

        int forma;
        int cantidad;

        cout << "1. Datos aleatorios" << endl;
        cout << "2. Datos capturados" << endl;
        cout << "Selecciona una opcion: ";
        cin >> forma;

        cout << "Cuantos elementos quieres agregar? ";
        cin >> cantidad;

        if (forma == 1) {

            string palabras[] = {
                "hola", "tec", "lista", "nodo",
                "casa", "perro", "gato"
            };

            for (int i = 0; i < cantidad; i++) {
                lista.push_back(palabras[rand() % 7]);
            }

        }
        else if (forma == 2) {

            for (int i = 0; i < cantidad; i++) {

                string dato;

                cout << "Dato " << i + 1 << ": ";
                cin >> dato;

                lista.push_back(dato);
            }
        }

        cout << "Lista creada: ";
        lista.print();

        menuStrings(lista);
    }


    else {
        cout << "Opcion invalida" << endl;
    }

    return 0;
}