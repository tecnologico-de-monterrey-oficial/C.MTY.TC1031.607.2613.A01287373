
// Carolina Vildósola Guzmán
// A01287373

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

struct PaginaWeb {
    string titulo;
    string url;
};

int main() {

    Stack<PaginaWeb> historial;
    int opcion;

    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Visitar una nueva página" << endl;
        cout << "2. Regresar a la página anterior" << endl;
        cout << "3. Ver la página actual" << endl;
        cout << "4. Ver cuantas páginas hay en el historial" << endl;
        cout << "5. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            PaginaWeb nueva;

            cout << "Titulo: ";
            cin >> nueva.titulo;

            cout << "url: ";
            cin >> nueva.url;

            historial.push(nueva);

            cout << "Página agregada al historial." << endl;
        }

        else if (opcion == 2) {
            try {
                PaginaWeb pagina = historial.pop();

                cout << "Página cerrada: " << pagina.titulo << endl;
                cout << "url: " << pagina.url << endl;
            }
            catch (out_of_range& error) {
                cout << error.what() << endl;
            }
        }

        else if (opcion == 3) {
            try {
                PaginaWeb pagina = historial.top();

                cout << "página actual: " << pagina.titulo << endl;
                cout << "url: " << pagina.url << endl;
            }
            catch (out_of_range& error) {
                cout << error.what() << endl;
            }
        }

        else if (opcion == 4) {
            cout << "Paginas en el historial: " << historial.getSize() << endl;
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