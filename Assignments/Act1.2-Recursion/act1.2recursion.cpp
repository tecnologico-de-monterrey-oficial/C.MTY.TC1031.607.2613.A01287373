
// Carolina Vildósola Guzmán
// A01287373

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int sumIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int sumRecursive(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumRecursive(n - 1);
}

int sumFormula(int n) {
    return (n * (n + 1)) / 2;
}

int fibonacciIterative(int n) {
    int a = 1;
    int b = 1;
    int c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacciRecursive(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int bacteriaIterative(int n){
    double born = 3.78;
    double died = 2.34;
    int sum =1;
    for (int i = 1; i <= n; i++) {
        int bac;
        int bacBorn = sum * born;
        int bacDied = sum * died;
        bac = bacBorn - bacDied;
        sum += bac;
    }
    return sum;
}

int bacteriaRecursive(int n){
    if (n == 0) {
        return 1;
    }
    int bacteria = bacteriaRecursive(n - 1);
    int born = bacteria * 3.78;
    int died = bacteria * 2.34;
    return bacteria + born - died;
}

double investmentRecursive(double amount, int n) {
    if (n == 0) {
        return amount;
    }
    return investmentRecursive(amount, n - 1) * 1.1875;

}

double investmentIterative(double amount, int n) {
    for (int i =1; i <= n; i++) {
        amount = amount * 1.1875;
    }
    return amount;
}

int powRecursive(int n, int y) {
    if (y == 0) {
        return 1;
    }
    return n * powRecursive(n, y - 1);
    }

int powIterative(int n, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result = result * n;
    }
    return result;
}



int main() {


    cout << "Factorial de 7: " << factorial(7) << endl;

    // suma iterativa
    cout << "Suma iterativa de 5: " << sumIterative(5) << endl;

    // suma recursiva
    cout << "Suma recursiva de 5: " << sumRecursive(5) << endl;

    // suma con formula
    cout << "Suma formula de 5: " << sumFormula(5) << endl;

    // fibonacci iterativa
    cout << "Fibonacci iterativa de 8: " << fibonacciIterative(8) << endl;

    // fibonacci recursiva
    cout << "Fibonacci recursiva de 8: " << fibonacciRecursive(8) << endl;

    // bacteria iterativa
    cout << "Bacteria iterativa de 5: " << bacteriaIterative(5) << endl;

    // bacteria recursiva
    cout << "Bacteria recursiva de 5: " << bacteriaRecursive(5) << endl;

    // inversión recursiva
    cout << "Inversion recursiva: " << investmentRecursive(1000, 3) << endl;

    cout << "Inversion iterativa: " << investmentIterative(1000, 3) << endl;

    // potencia recursiva

    cout << "Potencia recursiva de 2^4: " << powRecursive(2, 4) << endl;
    // potencia iterativa

    cout << "Potencia iterativa de 2^4: " << powIterative(2, 4) << endl;
    
    return 0;
}