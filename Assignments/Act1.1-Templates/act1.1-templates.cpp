
#include <iostream>
using namespace std;

#include "List.h"

// int sum(int a, int b) {
//     return a + b;
// }

// double sum(double a, double b) {
//     return a + b;
// }

// string sum(string a, string b) {
//     return a + b;
// }

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {

    string a= "hola ";
    string b= "crayola";
    cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << endl;
    int c= 5;
    int d= 10;
    cout << "Sum of " << c << " and " << d << " is: " << sum(c, d) << endl;
    double e= 5.5;
    double f= 10.5;
    cout << "Sum of " << e << " and " << f << " is: " << sum(e, f) << endl;

    List<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);

    List<string> things;
    things.insert("Laptop");
    things.insert("bottle");

    cout << "\nLista de enteros:" << endl;
list.print();

cout << "Size: " << list.getSize() << endl;

cout << "Dato en posicion 1: " << list.getData(1) << endl;

cout << "Maximo: " << list.getMax() << endl;

cout << "\nProbando insertAt:" << endl;
list.insertAt(1, 7);
list.print();

cout << "\nProbando removeAt:" << endl;
list.removeAt(1);
list.print();

cout << "\nProbando removeLast:" << endl;
list.removeLast();
list.print();

cout << "\nProbando posicion invalida:" << endl;
list.insertAt(100, 20);

cout << "\nProbando lista vacia:" << endl;
List<int> emptyList;
emptyList.removeLast();

    return 0;
}