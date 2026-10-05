

// Carolina Vildósola Guzmán
// A01287373

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <stdexcept>
using namespace std;

#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void push_front(T data);
    void push_back(T data);
    void print();
    void insert(int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T newData);
    int findData(T data);
    T& operator[](int index);
    LinkedList<T>& operator=(const LinkedList<T>& other);
};


template <typename T>
void LinkedList<T>::push_front(T data) {
    // crear un nodo nuevo
    Node<T>* node = new Node<T>(data);

    // el nuevo nodo apunta al que antes era el primero
    node->next = head;

    // ahora el nuevo nodo es head
    head = node;

    size++;
}


template <typename T>
void LinkedList<T>::push_back(T data) {
    // validamos si la lista esta vacia
    if (head != nullptr) {

        Node<T>* aux = head;

        // recorremos hasta llegar al ultimo nodo
        while (aux->next != nullptr) {
            aux = aux->next;
        }

        // agregamos el nuevo nodo al final
        aux->next = new Node<T>(data);
    }
    else {
        // si esta vacia, el nuevo nodo es head
        head = new Node<T>(data);
    }

    size++;
}


template <typename T>
void LinkedList<T>::insert(int index, T data) {

    // validamos que la posicion exista
    if (index >= 0 && index < size) {

        int auxIndex = 0;
        Node<T>* aux = head;

        // llegamos hasta el nodo del indice indicado
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }

        // insertamos despues de ese indice
        aux->next = new Node<T>(data, aux->next);

        size++;
    }
    else {
        throw out_of_range("La posicion no existe en la lista");
    }
}

template <typename T>
bool LinkedList<T>::deleteData(T data) {
    // validamos que la lista no este vacia
    if (head == nullptr) {
        return false;
    }

    // revisamos si queremos borrar el primer elemento
    if (head->data == data) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
        return true;
    }

    // recorremos la lista buscando el dato
    Node<T>* auxPrev = head;
    Node<T>* aux = head->next;

    while (aux != nullptr) {
        if (aux->data == data) {
            auxPrev->next = aux->next;
            delete aux;
            size--;
            return true;
        }

        auxPrev = aux;
        aux = aux->next;
    }

    return false;
}

template <typename T>
bool LinkedList<T>::deleteAt(int index) {
    // validamos que la posicion exista
    if (index < 0 || index >= size) {
        return false;
    }

    // borrar el primer elemento
    if (index == 0) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
        return true;
    }

    // llegamos al nodo anterior al que queremos borrar
    Node<T>* aux = head;

    for (int i = 0; i < index - 1; i++) {
        aux = aux->next;
    }

    Node<T>* borrar = aux->next;
    aux->next = borrar->next;

    delete borrar;
    size--;

    return true;
}


template <typename T>
T LinkedList<T>::getData(int index) {
    // validamos que la posicion exista
    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head;

    // recorremos hasta llegar a la posicion
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    return aux->data;
}

template <typename T>
void LinkedList<T>::updateData(T data, T newData) {
    Node<T>* aux = head;

    // buscamos el primer dato que sea igual
    while (aux != nullptr) {
        if (aux->data == data) {
            aux->data = newData;
            return;
        }

        aux = aux->next;
    }

    throw out_of_range("No se encontro el dato");
}

template <typename T>
void LinkedList<T>::updateAt(int index, T newData) {
    // validamos que la posicion exista
    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head;

    // recorremos hasta llegar a la posicion
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    aux->data = newData;
}

template <typename T>
int LinkedList<T>::findData(T data) {
    Node<T>* aux = head;
    int index = 0;

    // recorremos la lista buscando el dato
    while (aux != nullptr) {
        if (aux->data == data) {
            return index;
        }

        aux = aux->next;
        index++;
    }

    // si no encontramos el dato
    return -1;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    // validamos que la posicion exista
    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head;

    // recorremos hasta llegar a la posicion
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    return aux->data;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {

    // evitamos copiar la lista sobre ella misma
    if (this == &other) {
        return *this;
    }

    // borramos los nodos que ya tenia esta lista
    while (head != nullptr) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }

    size = 0;

    // recorremos la otra lista
    Node<T>* aux = other.head;

    while (aux != nullptr) {
        push_back(aux->data);
        aux = aux->next;
    }

    return *this;
}

template <typename T>
void LinkedList<T>::print() {

    Node<T>* aux = head;

    while (aux != nullptr) {

        cout << aux->data;

        aux = aux->next;

        if (aux != nullptr) {
            cout << " - ";
        }
    }

    cout << endl;
}


#endif