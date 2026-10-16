

// Carolina Vildósola Guzmán A01287373

#pragma once

#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T>
class Stack {
private:
    Node<T>* topNode;
    int size;

public:
    Stack() : topNode(nullptr), size(0) {}

    ~Stack() {
        while (topNode != nullptr) {
            Node<T>* aux = topNode;
            topNode = topNode->next;
            delete aux;
        }
    }

    // push
    void push(T data) {
        Node<T>* nuevo = new Node<T>(data);
        nuevo->next = topNode;
        topNode = nuevo;
        size++;
    }

    // pop
    T pop() {
        if (topNode == nullptr) {
            throw out_of_range("La pila esta vacia");
        }

        Node<T>* aux = topNode;
        T data = aux->data;

        topNode = topNode->next;
        delete aux;
        size--;

        return data;
    }

    // peek
    T peek() {
        if (topNode == nullptr) {
            throw out_of_range("La pila esta vacia");
        }

        return topNode->data;
    }

    // top
    T top() {
        return peek();
    }

    // isEmpty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // getSize
    int getSize() {
        return size;
    }
};