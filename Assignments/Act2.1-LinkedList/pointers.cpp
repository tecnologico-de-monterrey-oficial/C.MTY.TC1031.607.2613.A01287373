

// Carolina Vildósola Guzmán
// A01287373

#include <iostream>
#include "Fraction.h"
using namespace std;

int main(){

    int x = 42;
    int *p = &x;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << endl;

    cout << "valores de q: "  << endl;
    int* q = new int(5);
    cout << "q: " << q << endl;
    cout << "*q: " << *q << endl;

    delete q; //buena practica liberar memoria dinamica
    cout << "q: " << q << endl;
    cout << "*q: " << *q << endl; 


    Fraction* f = new Fraction(2, 3);
    cout << "f: " << f << endl;
    cout << "*f: " << *f << endl;

    delete f; // liberar memoria dinamica
    cout << "f: " << f << endl;
    cout << "*f: " << *f << endl;

    return 0;
}
 // sirve para memoria dinamica
 

 // pragma once
 #include <memory>

 template <typename T>
 strct Node {
     T data;
     std::shared_ptr<Node<T>> next;

     Node(const T& value) : data(value), next(nullptr) {}
     Node(const T& value, std::unique_ptr<Node<T>> nextNode) : data(value), next(nextNode) {}
 };


