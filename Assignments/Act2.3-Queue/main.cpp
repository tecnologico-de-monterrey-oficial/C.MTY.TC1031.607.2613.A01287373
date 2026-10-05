
// Carolina Vildósola Guzmán
// A01287373

#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

struct Cliente {
    string nombre;
    int boletos;
};

int main() {

    Queue<Cliente> fila;
    int opcion;

    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Agregar un cliente a la fila" << endl;
        cout << "2. Atender al siguiente cliente" << endl;
        cout << "3. Ver quien sigue en la fila" << endl;
        cout << "4. Ver cuantas personas hay en la fila" << endl;
        cout << "5. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            Cliente nuevo;

            cout << "Nombre: ";
            cin >> nuevo.nombre;

            cout << "Cantidad de boletos: ";
            cin >> nuevo.boletos;

            fila.push(nuevo);

            cout << "Cliente agregado" << endl;
        }

        else if (opcion == 2) {
            try {
                Cliente cliente = fila.pop();

                cout << "Cliente atendido: " << cliente.nombre << endl;
                cout << "Boletos solicitados: " << cliente.boletos << endl;
            }
            catch (out_of_range& error) {
                cout << error.what() << endl;
            }
        }

        else if (opcion == 3) {
            try {
                Cliente cliente = fila.front();

                cout << "Siguiente cliente: " << cliente.nombre << endl;
                cout << "Boletos solicitados: " << cliente.boletos << endl;
            }
            catch (out_of_range& error) {
                cout << error.what() << endl;
            }
        }

        else if (opcion == 4) {
            cout << "Personas en la fila: " << fila.getSize() << endl;
        }

        else if (opcion == 5) {
            cout << "Fin del programa" << endl;
        }

        else {
            cout << "Opción inválida." << endl;
        }

    } while (opcion != 5);

    return 0;
}