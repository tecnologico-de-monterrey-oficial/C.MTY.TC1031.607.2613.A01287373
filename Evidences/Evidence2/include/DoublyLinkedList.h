

// Carolina Vildósola Guzmán A01287373
#pragma once

#include <iostream>
#include <stdexcept>
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

    ~DoublyLinkedList() {
        while (head != nullptr) {
            NodeD<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }
    // getNode
NodeD<T>* getNode(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }

    NodeD<T>* aux = head;

    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    return aux;
}

    // addFirst
    void addFirst(T data) {
        NodeD<T>* nuevo = new NodeD<T>(data);

        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            nuevo->next = head;
            head->prev = nuevo;
            head = nuevo;
        }

        size++;
    }

    // addLast
    void addLast(T data) {
        NodeD<T>* nuevo = new NodeD<T>(data);

        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            nuevo->prev = tail;
            tail->next = nuevo;
            tail = nuevo;
        }

        size++;
    }

    // insert
    void insert(int index, T data) {
        if (index < 0 || index >= size) {
            throw out_of_range("Indice invalido");
        }

        if (index == size - 1) {
            addLast(data);
            return;
        }

        NodeD<T>* aux = head;

        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }

        NodeD<T>* nuevo = new NodeD<T>(data);

        nuevo->prev = aux;
        nuevo->next = aux->next;

        aux->next->prev = nuevo;
        aux->next = nuevo;

        size++;
    }


    // insertAfter
    void insertAfter(NodeD<T>* node, T data) {
    if (node == nullptr) {
        throw invalid_argument("Nodo invalido");
    }

    NodeD<T>* nuevo = new NodeD<T>(data);

    nuevo->next = node->next;
    nuevo->prev = node;

    if (node->next != nullptr) {
        node->next->prev = nuevo;
    } else {
        tail = nuevo;
    }

    node->next = nuevo;
    size++;
}

    // deleteAt
    bool deleteAt(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        NodeD<T>* aux = head;

        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }

        // conectamos el nodo anterior
        if (aux->prev != nullptr) {
            aux->prev->next = aux->next;
        } else {
            head = aux->next;
        }

        // conectamos el nodo siguiente
        if (aux->next != nullptr) {
            aux->next->prev = aux->prev;
        } else {
            tail = aux->prev;
        }

        delete aux;
        size--;

        return true;
    }

    // deleteNode
    bool deleteNode(NodeD<T>* node) {
    if (node == nullptr) {
        return false;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
    size--;

    return true;
}

    // print
    void print() {
        NodeD<T>* aux = head;

        while (aux != nullptr) {
            cout << aux->data;
            aux = aux->next;

            if (aux != nullptr) {
                cout << " - ";
            }
        }

        cout << endl;
    }

    // printBackward
    void printBackward() {
        NodeD<T>* aux = tail;

        while (aux != nullptr) {
            cout << aux->data;
            aux = aux->prev;

            if (aux != nullptr) {
                cout << " - ";
            }
        }

        cout << endl;
    }

    // getSize
    int getSize() {
        return size;
    }
};