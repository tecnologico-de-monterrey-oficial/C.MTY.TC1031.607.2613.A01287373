

// Carolina Vildósola Guzmán A01287373


#include <iostream>
#include <stdexcept>

#include "../include/LinkedList.h"
#include "../include/Stack.h"
#include "../include/Queue.h"
#include "../include/DoublyLinkedList.h"

using namespace std;

int main() {

    //  simple linked list

    cout << "\nLISTA SIMPLE" << endl;

    LinkedList<int> lista;

    cout << "Lista vacia: ";
    lista.print();
    cout << "Tamano: " << lista.getSize() << endl;

    // probamos con un elemento
    lista.push_front(20);

    cout << "Un elemento: ";
    lista.print();

    // agregamos al principio y al final
    lista.push_front(10);
    lista.push_back(30);

    cout << "Lista con tres elementos: ";
    lista.print();

    // eliminamos el primero
    cout << "Eliminamos: " << lista.pop_front() << endl;

    cout << "Lista actual: ";
    lista.print();

    cout << "Tamano: " << lista.getSize() << endl;

    // eliminamos los elementos restantes
    lista.pop_front();
    lista.pop_front();

    cout << "Lista despues de eliminar todos: ";
    lista.print();

    cout << "Tamano final: " << lista.getSize() << endl;

    // probamos eliminar cuando esta vacia
    try {
        lista.pop_front();
    }
    catch (out_of_range& error) {
        cout << "Error controlado: " << error.what() << endl;
    }


    //PILA

    cout << "\n PILA " << endl;

    Stack<int> pila;

    cout << "Esta vacia? "
         << (pila.isEmpty() ? "Si" : "No") << endl;

    // probamos sacar un elemento de una pila vacia
    try {
        pila.pop();
    }
    catch (out_of_range& error) {
        cout << "Error controlado: " << error.what() << endl;
    }

    // probamos con un elemento
    pila.push(10);

    cout << "Un elemento, peek: " << pila.peek() << endl;

    // agregamos mas elementos
    pila.push(20);
    pila.push(30);

    cout << "Tamano: " << pila.getSize() << endl;

    // comprobamos LIFO
    cout << "Orden LIFO: ";

    while (!pila.isEmpty()) {
        cout << pila.pop() << " ";
    }

    cout << endl;

    cout << "Tamano final: " << pila.getSize() << endl;

    cout << "Esta vacia? "
         << (pila.isEmpty() ? "Si" : "No") << endl;


    // FILA

    cout << "\nFILA " << endl;

    Queue<int> fila;

    cout << "Esta vacia? "
         << (fila.isEmpty() ? "Si" : "No") << endl;

    // probamos sacar un elemento de una fila vacia
    try {
        fila.dequeue();
    }
    catch (out_of_range& error) {
        cout << "Error controlado: " << error.what() << endl;
    }

    // probamos con un elemento
    fila.enqueue(10);

    cout << "Un elemento, front: " << fila.front() << endl;

    // agregamos mas elementos
    fila.enqueue(20);
    fila.enqueue(30);

    cout << "Tamano: " << fila.getSize() << endl;

    // comprobamos FIFO
    cout << "Orden FIFO: ";

    while (!fila.isEmpty()) {
        cout << fila.dequeue() << " ";
    }

    cout << endl;

    cout << "Tamano final: " << fila.getSize() << endl;

    cout << "Esta vacia? "
         << (fila.isEmpty() ? "Si" : "No") << endl;


    // lista doble linked

    cout << "\nLISTA DOBLE " << endl;

    DoublyLinkedList<int> doble;

    cout << "Lista vacia: ";
    doble.print();

    cout << "Tamano: " << doble.getSize() << endl;

    // probamos con un elemento
    doble.addFirst(20);

    cout << "Un elemento: ";
    doble.print();

    // agregamos al principio y al final
    doble.addFirst(10);
    doble.addLast(30);

    cout << "Lista con tres elementos: ";
    doble.print();

    // insertamos despues del indice 1
    doble.insert(1, 25);

    cout << "Insertamos 25 despues del indice 1: ";
    doble.print();

    // recorremos hacia adelante
    cout << "Recorrido hacia adelante: ";
    doble.print();

    // recorremos hacia atras
    cout << "Recorrido hacia atras: ";
    doble.printBackward();

    cout << "Tamano: " << doble.getSize() << endl;

    // eliminamos el primer elemento
    doble.deleteAt(0);

    cout << "Eliminamos el primero: ";
    doble.print();

    // eliminamos el ultimo elemento
    doble.deleteAt(doble.getSize() - 1);

    cout << "Eliminamos el ultimo: ";
    doble.print();

    // eliminamos hasta dejar un solo elemento
    doble.deleteAt(0);

    cout << "Lista con un elemento: ";
    doble.print();

    // eliminamos el unico elemento
    doble.deleteAt(0);

    cout << "Lista despues de eliminar todos: ";
    doble.print();

    cout << "Tamañoo final: " << doble.getSize() << endl;

    // probamos eliminar de una lista vacia
    if (!doble.deleteAt(0)) {
        cout << "No se puede eliminar: lista vacia" << endl;
    }


    return 0;
}