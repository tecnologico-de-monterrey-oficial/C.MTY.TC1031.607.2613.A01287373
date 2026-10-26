

// Carolina Vildósola Guzmán A01287373
// Carolina Vildósola Guzmán A01287373

#include <iostream>
#include <limits>
#include "BST.h"

using namespace std;

int main() {

    BST<int> arbol;

    int option = 0;
    int data;
    int recorrido;

    do {
        cout << "\n MENU " << endl;
        cout << "1. Insertar un dato" << endl;
        cout << "2. Mostrar recorridos" << endl;
        cout << "3. Buscar un dato" << endl;
        cout << "4. Mostrar altura" << endl;
        cout << "5. Mostrar ancestros" << endl;
        cout << "6. Consultar nivel" << endl;
        cout << "7. Mostrar arbol" << endl;
        cout << "8. Eliminar un dato" << endl;
        cout << "9. Salir" << endl;
        cout << "Selecciona una opción: ";

        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opción inválida" << endl;
            continue;
        }

        switch (option) {

            case 1:
                cout << "Dato a insertar: ";
                if (cin >> data) {
                    if (arbol.find(data)) {
                        cout << "El dato ya existe" << endl;
                    } else {
                        arbol.insert(data);
                        cout << "Dato insertado" << endl;
                    }
                }
                break;

            case 2:
                cout << "\n1. Preorder" << endl;
                cout << "2. Inorder" << endl;
                cout << "3. Postorder" << endl;
                cout << "4. Por niveles" << endl;
                cout << "Selecciona el recorrido: ";

                if (cin >> recorrido) {
                    arbol.visit(recorrido);
                }
                break;

            case 3:
                cout << "Dato a buscar: ";
                if (cin >> data) {
                    if (arbol.find(data)) {
                        cout << "El dato si existe" << endl;
                    } else {
                        cout << "El dato no existe" << endl;
                    }
                }
                break;

            case 4:
                cout << "Altura del arbol: "
                     << arbol.height() << endl;
                break;

            case 5:
                cout << "Dato para ver sus ancestros: ";
                if (cin >> data) {
                    arbol.ancestors(data);
                }
                break;

            case 6:
                cout << "Dato para consultar su nivel: ";
                if (cin >> data) {
                    cout << "Nivel: "
                         << arbol.whatLevelAmI(data) << endl;
                }
                break;

            case 7:
                arbol.print();
                break;

            case 8:
                cout << "Dato a eliminar: ";
                if (cin >> data) {
                    if (arbol.find(data)) {
                        arbol.remove(data);
                        cout << "Dato eliminado" << endl;
                    } else {
                        cout << "El dato no existe" << endl;
                    }
                }
                break;

            case 9:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción inválida" << endl;
                break;
        }

        // limpiamos la entrada si escribieron algo incorrecto
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Escribe un número válido" << endl;
        }

    } while (option != 9);

    return 0;
}