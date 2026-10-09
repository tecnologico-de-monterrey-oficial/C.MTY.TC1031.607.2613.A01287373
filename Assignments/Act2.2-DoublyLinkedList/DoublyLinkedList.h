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


// AGREGAR AL PRINCIPIO

template <typename T>
void DoublyLinkedList<T>::addFirst(T data) {
    // validamos si la lista está vacía
    if (head == nullptr) {
        // apuntamos head a un nuevo nodo
        head = new NodeD<T>(data);
        // apuntamos tail a head
        tail = head;
        // incrementamos size
        size++;
    } else {
        // creamos un nuevo nodo
        NodeD<T>* aux = new NodeD<T>(data);
        // apuntamos el next de aux a head
        aux->next = head;
        // apuntamos el prev de head a aux
        head->prev = aux;
        // actualizamos head
        head = aux;
        // incrementamos size
        size++;
    }
}


// AGREGAR AL FINAL

template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
    // validamos si la lista está vacía
    if (head == nullptr) {
        // apuntamos head a un nuevo nodo
        head = new NodeD<T>(data);
        // apuntamos tail a head
        tail = head;
        // incrementamos size
        size++;
    } else {
        // creamos un nuevo nodo
        NodeD<T>* aux = new NodeD<T>(data);
        // apuntamos el prev de aux a tail
        aux->prev = tail;
        // apuntamos el next de tail a aux
        tail->next = aux;
        // actualizamos tail
        tail = aux;
        // incrementamos size
        size++;
    }
}


// INSERTAR DESPUES DE UN INDICE

template <typename T>
void DoublyLinkedList<T>::insert(int index, T data) {
    // validamos que el índice sea válido
    if (index >= 0 && index < size) {

        // validamos si queremos insertar después del último
        if (index == size - 1) {
            addLast(data);
        } else {
            // creamos un apuntador auxiliar
            NodeD<T>* aux = head;

            // recorremos hasta llegar al índice
            for (int i = 0; i < index; i++) {
                aux = aux->next;
            }

            // creamos un nuevo nodo
            NodeD<T>* auxNew = new NodeD<T>(data);

            // actualizamos los apuntadores del nuevo nodo
            auxNew->prev = aux;
            auxNew->next = aux->next;

            // actualizamos los apuntadores de los otros nodos
            aux->next->prev = auxNew;
            aux->next = auxNew;

            // incrementamos size
            size++;
        }

    } else {
        throw out_of_range("Indice invalido");
    }
}


// BORRAR POR POSICION

template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    // validamos que el índice sea válido
    if (index < 0 || index >= size) {
        return false;
    }

    // validamos si solo hay un elemento
    if (head == tail) {
        // creamos un nodo auxiliar
        NodeD<T>* aux = head;

        // apuntamos head y tail a nullptr
        head = nullptr;
        tail = nullptr;

        // borramos aux
        delete aux;

        // decrementamos size
        size--;
        return true;
    }

    // validamos si queremos borrar el primero
    if (index == 0) {
        // creamos un nodo auxiliar
        NodeD<T>* aux = head;

        // actualizamos head
        head = head->next;
        head->prev = nullptr;

        // borramos aux
        delete aux;

        // decrementamos size
        size--;
        return true;
    }

    // validamos si queremos borrar el último
    if (index == size - 1) {
        // creamos un nodo auxiliar
        NodeD<T>* aux = tail;

        // actualizamos tail
        tail = tail->prev;
        tail->next = nullptr;

        // borramos aux
        delete aux;

        // decrementamos size
        size--;
        return true;
    }

    // si no es el primero ni el último, borramos uno de en medio
    NodeD<T>* aux = head;

    // recorremos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // actualizamos los apuntadores
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;

    // borramos aux
    delete aux;

    // decrementamos size
    size--;
    return true;
}


// BUSCAR UN DATO

template <typename T>
int DoublyLinkedList<T>::findData(T data) {
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // inicializamos un índice auxiliar
    int auxIndex = 0;

    // recorremos la lista
    while (aux != nullptr) {
        // validamos si encontramos el dato
        if (aux->data == data) {
            return auxIndex;
        }

        // avanzamos al siguiente nodo
        aux = aux->next;
        auxIndex++;
    }

    // si no encontramos el dato regresamos -1
    return -1;
}


// BORRAR UN DATO

template <typename T>
bool DoublyLinkedList<T>::deleteData(T data) {
    // buscamos la posición del dato
    int index = findData(data);

    // validamos si encontramos el dato
    if (index == -1) {
        return false;
    }

    // borramos el dato usando su posición
    return deleteAt(index);
}


// OBTENER UN DATO POR POSICION

template <typename T>
T DoublyLinkedList<T>::getData(int index) {
    // validamos que el índice sea válido
    if (index < 0 || index >= size) {
        throw out_of_range("Indice invalido");
    }

    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // recorremos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // regresamos el dato
    return aux->data;
}


// ACTUALIZAR UN DATO

template <typename T>
void DoublyLinkedList<T>::updateData(T data, T newData) {
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr) {
        // validamos si encontramos el dato
        if (aux->data == data) {
            // actualizamos el dato
            aux->data = newData;
            return;
        }

        // avanzamos al siguiente nodo
        aux = aux->next;
    }

    // si no encontramos el dato
    throw out_of_range("No se encontro el dato");
}


// ACTUALIZAR POR POSICION

template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    // validamos que el índice sea válido
    if (index < 0 || index >= size) {
        throw out_of_range("Indice invalido");
    }

    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // recorremos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // actualizamos el dato
    aux->data = newData;
}


// OPERADOR []

template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    // validamos que el índice sea válido
    if (index < 0 || index >= size) {
        throw out_of_range("Indice invalido");
    }

    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // recorremos hasta llegar a la posición
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    // regresamos el dato para poder leerlo o cambiarlo
    return aux->data;
}


// OPERADOR =

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(
    const DoublyLinkedList<T>& other) {

    // validamos que no sea la misma lista
    if (this != &other) {
        // limpiamos la lista actual
        clear();

        // creamos un apuntador a la otra lista
        NodeD<T>* aux = other.head;

        // recorremos la otra lista
        while (aux != nullptr) {
            // agregamos cada dato a nuestra lista
            addLast(aux->data);

            // avanzamos al siguiente nodo
            aux = aux->next;
        }
    }

    // regresamos la lista actual
    return *this;
}


// LIMPIAR LA LISTA

template <typename T>
void DoublyLinkedList<T>::clear() {
    // recorremos mientras haya nodos
    while (head != nullptr) {
        // creamos un nodo auxiliar
        NodeD<T>* aux = head;

        // avanzamos head
        head = head->next;

        // borramos aux
        delete aux;
    }

    // dejamos la lista vacía
    head = nullptr;
    tail = nullptr;
    size = 0;
}


// ORDENAR LA LISTA

template <typename T>
void DoublyLinkedList<T>::sort() {
    // validamos si hay más de un elemento
    if (size < 2) {
        return;
    }

    // usamos bubble sort para ordenar
    for (int i = 0; i < size - 1; i++) {
        NodeD<T>* aux = head;

        // recorremos los elementos
        for (int j = 0; j < size - i - 1; j++) {

            // comparamos el dato actual con el siguiente
            if (aux->data > aux->next->data) {
                // intercambiamos los datos
                swap(aux->data, aux->next->data);
            }

            // avanzamos al siguiente nodo
            aux = aux->next;
        }
    }
}


// DUPLICAR CADA ELEMENTO

template <typename T>
void DoublyLinkedList<T>::duplicate() {
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr) {
        // creamos un nodo con el mismo dato
        NodeD<T>* nuevo = new NodeD<T>(aux->data);

        // apuntamos el nuevo nodo después de aux
        nuevo->next = aux->next;
        nuevo->prev = aux;

        // validamos si hay un nodo después
        if (aux->next != nullptr) {
            aux->next->prev = nuevo;
        } else {
            // si era el último actualizamos tail
            tail = nuevo;
        }

        // actualizamos el next de aux
        aux->next = nuevo;

        // incrementamos size
        size++;

        // avanzamos al siguiente dato original
        aux = nuevo->next;
    }
}


// ELIMINAR DATOS DUPLICADOS

template <typename T>
void DoublyLinkedList<T>::removeDuplicates() {
    // primero ordenamos la lista
    sort();

    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr && aux->next != nullptr) {

        // validamos si dos datos seguidos son iguales
        if (aux->data == aux->next->data) {
            // guardamos el nodo que vamos a borrar
            NodeD<T>* borrar = aux->next;

            // actualizamos el next de aux
            aux->next = borrar->next;

            // validamos si hay otro nodo después
            if (borrar->next != nullptr) {
                borrar->next->prev = aux;
            } else {
                // si borramos el último actualizamos tail
                tail = aux;
            }

            // borramos el nodo repetido
            delete borrar;

            // decrementamos size
            size--;
        } else {
            // avanzamos al siguiente nodo
            aux = aux->next;
        }
    }
}


// MOSTRAR LA LISTA

template <typename T>
void DoublyLinkedList<T>::print() {
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;

    // recorremos la lista
    while (aux != nullptr) {
        // mostramos el dato
        cout << aux->data;

        // avanzamos al siguiente nodo
        aux = aux->next;

        // mostramos un separador si hay otro dato
        if (aux != nullptr) {
            cout << " - ";
        }
    }

    cout << endl;
}


// OBTENER EL TAMAÑO

template <typename T>
int DoublyLinkedList<T>::getSize() {
    return size;
}


// DESTRUCTOR

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    // liberamos los nodos cuando se termina de usar la lista
    clear();
}

#endif