// Caro Vildósola A01287373

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <iostream>
#include <stdexcept>
#include <utility>
#include "NodeD.h"

using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // constructor para copiar otra lista
    DoublyLinkedList(const DoublyLinkedList<T>& other) : head(nullptr), tail(nullptr), size(0) {
        // creamos un apuntador auxiliar
        NodeD<T>* aux = other.head;

        // recorremos la otra lista
        while (aux != nullptr) {
            // agregamos el dato a nuestra lista
            addLast(aux->data);

            // avanzamos al siguiente nodo
            aux = aux->next;
        }
    }

    ~DoublyLinkedList();

    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);

    bool deleteAt(int index);
    bool deleteData(T data);

    T getData(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T newData);
    int findData(T data);

    T& operator[](int index);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);

    void clear();
    void sort();
    void duplicate();
    void removeDuplicates();

    void print();
    int getSize();
};


// addFirst

template <typename T>
void DoublyLinkedList<T>::addFirst(T data) {
    // vemos si la lista está vacía
    if (head == nullptr) {
        // creamos el primer nodo
        head = new NodeD<T>(data);

        // como es el único, también es el último
        tail = head;

        // aumentamos el tamaño
        size++;
    } else {
        // creamos un nodo nuevo
        NodeD<T>* aux = new NodeD<T>(data);

        // conectamos el nuevo nodo con el primero
        aux->next = head;
        head->prev = aux;

        // ahora el nuevo nodo es el primero
        head = aux;

        // aumentamos el tamaño
        size++;
    }
}


// addLast

template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
    // vemos si la lista está vacía
    if (head == nullptr) {
        // creamos el primer nodo
        head = new NodeD<T>(data);

        // como es el único, también es el último
        tail = head;

        // aumentamos el tamaño
        size++;
    } else {
        // creamos un nodo nuevo
        NodeD<T>* aux = new NodeD<T>(data);

        // conectamos el nuevo nodo con el último
        aux->prev = tail;
        tail->next = aux;

        // ahora el nuevo nodo es el último
        tail = aux;

        // aumentamos el tamaño
        size++;
    }
}


// insert

template <typename T>
void DoublyLinkedList<T>::insert(int index, T data) {
    // revisamos que el índice exista
    if (index >= 0 && index < size) {

        // si es el último, agregamos al final
        if (index == size - 1) {
            addLast(data);
        } else {
            // empezamos desde el primer nodo
            NodeD<T>* aux = head;

            // avanzamos hasta encontrar el índice
            for (int i = 0; i < index; i++) {
                aux = aux->next;
            }

            // creamos el nodo nuevo
            NodeD<T>* auxNew = new NodeD<T>(data);

            // conectamos el nuevo nodo con los demás
            auxNew->prev = aux;
            auxNew->next = aux->next;

            // actualizamos las conexiones
            aux->next->prev = auxNew;
            aux->next = auxNew;

            // aumentamos el tamaño
            size++;
        }

    } else {
        // si el índice no existe, mostramos un error
        throw out_of_range("Indice invalido");
    }
}


// deleteAt

template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    // revisamos que el índice exista
    if (index < 0 || index >= size) {
        return false;
    }

    // vemos si solo hay un elemento
    if (head == tail) {
        // guardamos el nodo que vamos a borrar
        NodeD<T>* aux = head;

        // dejamos la lista vacía
        head = nullptr;
        tail = nullptr;

        // borramos el nodo
        delete aux;

        // disminuimos el tamaño
        size--;
        return true;
    }

    // vemos si queremos borrar el primero
    if (index == 0) {
        // guardamos el primer nodo
        NodeD<T>* aux = head;

        // ahora el segundo nodo sera el primero
        head = head->next;
        head->prev = nullptr;

        // borramos el nodo anterior
        delete aux;

        // disminuimos el tamaño
        size--;
        return true;
    }

    // vemos si queremos borrar el ultimo
    if (index == size - 1) {
        // guardamos el último nodo
        NodeD<T>* aux = tail;

        // ahora el anterior será el ultimo
        tail = tail->prev;
        tail->next = nullptr;

        // borramos el nodo
        delete aux;

        // disminuimos el tamaño
        size--;
        return true;
    }

    // si está en medio, buscamos el nodo
    NodeD<T>* aux = head;

    // avanzamos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // conectamos el nodo anterior con el siguiente
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;

    // borramos el nodo
    delete aux;

    // disminuimos el tamaño
    size--;
    return true;
}


// findData

template <typename T>
int DoublyLinkedList<T>::findData(T data) {
    // empezamos desde el primer nodo
    NodeD<T>* aux = head;

    // empezamos contando desde el indice 0
    int auxIndex = 0;

    // recorremos la lista
    while (aux != nullptr) {
        // vemos si encontramos el dato
        if (aux->data == data) {
            // regresamos su posición
            return auxIndex;
        }

        // avanzamos al siguiente nodo
        aux = aux->next;
        auxIndex++;
    }

    // si no existe regresamos 1
    return -1;
}


// deleteData

template <typename T>
bool DoublyLinkedList<T>::deleteData(T data) {
    // buscamos en cual posición está el dato
    int index = findData(data);

    // vemos si encontramos el dato
    if (index == -1) {
        return false;
    }

    // borramos el dato usando su posición
    return deleteAt(index);
}


// getData

template <typename T>
T DoublyLinkedList<T>::getData(int index) {
    // revisamos que el índice exista
    if (index < 0 || index >= size) {
        throw out_of_range("Indice invalido");
    }

    // empezamos desde el primer nodo
    NodeD<T>* aux = head;

    // avanzamos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // regresamos el dato que encontramos
    return aux->data;
}


// updateData

template <typename T>
void DoublyLinkedList<T>::updateData(T data, T newData) {
    // empezamos desde el primer nodo
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr) {
        // vemos si encontramos el dato
        if (aux->data == data) {
            // cambiamos el dato por el nuevo
            aux->data = newData;
            return;
        }

        // avanzamos al siguiente nodo
        aux = aux->next;
    }

    // si no encontramos el dato, mostramos un error
    throw out_of_range("No se encontro el dato");
}


// updateAt

template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    // revisamos que el índice exista
    if (index < 0 || index >= size) {
        throw out_of_range("Indice invalido");
    }

    // empezamos desde el primer nodo
    NodeD<T>* aux = head;

    // avanzamos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // cambiamos el dato por el nuevo
    aux->data = newData;
}


// operator[]

template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    // revisamos que el indice exista
    if (index < 0 || index >= size) {
        throw out_of_range("Indice invalido");
    }

    // empezamos desde el primer nodo
    NodeD<T>* aux = head;

    // avanzamos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // regresamos el dato para leerlo o cambiarlo
    return aux->data;
}


// operator=

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(
    const DoublyLinkedList<T>& other) {

    // revisamos que no sea la misma lista
    if (this != &other) {
        // borramos los datos que teníamos
        clear();

        // empezamos desde el primer nodo de la otra lista
        NodeD<T>* aux = other.head;

        // recorremos la otra lista
        while (aux != nullptr) {
            // copiamos cada dato
            addLast(aux->data);

            // avanzamos al siguiente nodo
            aux = aux->next;
        }
    }

    // regresamos nuestra lista
    return *this;
}


// clear

template <typename T>
void DoublyLinkedList<T>::clear() {
    // recorremos mientras todavia haya nodos
    while (head != nullptr) {
        // guardamos el primer nodo
        NodeD<T>* aux = head;

        // avanzamos al siguiente nodo
        head = head->next;

        // borramos el nodo anterior
        delete aux;
    }

    // dejamos la lista vacía
    head = nullptr;
    tail = nullptr;
    size = 0;
}


// sort

template <typename T>
void DoublyLinkedList<T>::sort() {
    // vemos si hay suficientes datos para ordenar
    if (size < 2) {
        return;
    }

    // usamos bubble sort para ordenar
    for (int i = 0; i < size - 1; i++) {
        NodeD<T>* aux = head;

        // recorremos los elementos
        for (int j = 0; j < size - i - 1; j++) {

            // comparamos el dato con el siguiente
            if (aux->data > aux->next->data) {
                // si están al revés, los cambiamos
                swap(aux->data, aux->next->data);
            }

            // avanzamos al siguiente nodo
            aux = aux->next;
        }
    }
}


// duplicate

template <typename T>
void DoublyLinkedList<T>::duplicate() {
    // empezamos desde el primer nodo
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr) {
        // creamos otro nodo con el mismo dato
        NodeD<T>* nuevo = new NodeD<T>(aux->data);

        // ponemos el nuevo nodo después del original
        nuevo->next = aux->next;
        nuevo->prev = aux;

        // vemos si hay otro nodo después
        if (aux->next != nullptr) {
            // conectamos el siguiente con el nuevo
            aux->next->prev = nuevo;
        } else {
            // si era el último, actualizamos tail
            tail = nuevo;
        }

        // conectamos el original con el nuevo
        aux->next = nuevo;

        // aumentamos el tamaño
        size++;

        // avanzamos al siguiente dato original
        aux = nuevo->next;
    }
}


// removeDuplicates

template <typename T>
void DoublyLinkedList<T>::removeDuplicates() {
    // primero ordenamos la lista
    sort();

    // empezamos desde el 1er nodo
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr && aux->next != nullptr) {

        // vemos si el dato es igual al siguiente
        if (aux->data == aux->next->data) {
            // guardamos el nodo repetido
            NodeD<T>* borrar = aux->next;

            // conectamos aux con el nodo que sigue
            aux->next = borrar->next;

            // vemos si hay otro nodo después
            if (borrar->next != nullptr) {
                // actualizamos su conexión anterior
                borrar->next->prev = aux;
            } else {
                // si borramos el último, actualizamos tail
                tail = aux;
            }

            // borramos el dato repetido
            delete borrar;

            // disminuimos el tamaño
            size--;
        } else {
            // avanzamos al siguiente nodo
            aux = aux->next;
        }
    }
}


// print

template <typename T>
void DoublyLinkedList<T>::print() {
    // empezamos desde el 1er nodo
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr) {
        // mostramos el dato
        cout << aux->data;

        // avanzamos al sig nodo
        aux = aux->next;

        // si hay otro dato, mostramos un separador
        if (aux != nullptr) {
            cout << " - ";
        }
    }

    cout << endl;
}


// getSize

template <typename T>
int DoublyLinkedList<T>::getSize() {
    // regresamos la cantidad de elementos
    return size;
}


// destructor

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    // borramos los nodos cuando dejamos de usar la lista
    clear();
}

#endif


// fin