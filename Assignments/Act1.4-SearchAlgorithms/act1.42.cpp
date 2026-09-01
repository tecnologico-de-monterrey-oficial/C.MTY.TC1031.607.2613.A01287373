

// PROGRAMA 2
// Carolina Vildósola Guzmán
// A01287373

#include <iostream>
#include <string>

using namespace std;


// Busqueda secuencial
char sequentialSearch(string texto, int &comparaciones) {

    comparaciones = 0;

    for (int i = 0; i < texto.size() - 1; i += 2) {

        comparaciones++;

        if (texto[i] != texto[i + 1]) {
            return texto[i];
        }
    }

    return texto[texto.size() - 1];
}


char binarySearch(string texto, int &comparaciones) {

    int left = 0;
    int right = texto.size() - 1;

    comparaciones = 0;

    while (left < right) {

        int mid = (left + right) / 2;

        if (mid % 2 == 1) {
            mid--;
        }

        comparaciones++;

        if (texto[mid] != texto[mid + 1]) {
            return texto[mid];
        }

        left = mid + 2;
    }

    if (texto[left] != texto[left - 1]) {
        comparaciones++;
    }

    return texto[left];
}


int main() {

    int n;

    cout << "Cantidad de strings: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        string texto;

        cout << "Ingresa un string: ";
        cin >> texto;

        int comparaciones;
        int comparacionesBinarias;

        char unico = sequentialSearch(texto, comparaciones);
        char unicoBinario = binarySearch(texto, comparacionesBinarias);

        cout << "Resultado: "
             << unico << " " << comparaciones << " "
             << unicoBinario << " " << comparacionesBinarias << endl;
    }

    return 0;
}