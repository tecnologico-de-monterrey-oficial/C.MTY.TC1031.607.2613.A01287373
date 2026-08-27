
// Carolina Vildósola Guzmán 
// A01287373

#include <iostream>
#include <vector>
using namespace std;


/*
1. 0(1)
2. 0(log n)
3. 0(n)
4. 0(n log n)
5. 0(n^2)
6. 0(n^3)
7. 0(2^n)

*/


int sumaImparesIterative(vector<int> &numeros){ // 0(n)
    int suma = 0;
    for (int i = 0; i < numeros.size(); i++) {
        if (numeros[i] % 2 != 0) {
            suma += numeros[i];
        }
    }
    return suma;
}

int sumaImparesRecursive(vector<int> &numeros, int i) { // 0(n)
    if (i == numeros.size()) {
        return 0;
    }
    if (numeros[i] % 2 != 0) {
        return numeros[i] + sumaImparesRecursive(numeros, i + 1);
    }
    return sumaImparesRecursive(numeros, i + 1);

}



int main() {
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int suma = sumaImparesIterative(numeros);
    cout << "La suma de los números impares es: " << suma << endl;
    cout << "La suma recursiva de los números impares es: "
     << sumaImparesRecursive(numeros, 0) << endl;
    return 0;
}

