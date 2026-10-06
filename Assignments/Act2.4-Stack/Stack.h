
// Carolina Vildósola Guzmán
// A01287373

#ifndef Stack_h
#define Stack_h

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

    void push(T data);
    T pop();
    T top();
    int getSize();
};

template <typename T>
void Stack<T>::push(T data) {
    Node<T>* nuevo = new Node<T>(data);
    nuevo->next = topNode;
    topNode = nuevo;
    size++;
}

template <typename T>
T Stack<T>::pop() {
    if (topNode == nullptr) {
        throw out_of_range("El historial esta vacio");
    }

    Node<T>* aux = topNode;
    T data = aux->data;

    topNode = topNode->next;
    delete aux;
    size--;

    return data;
}

template <typename T>
T Stack<T>::top() {
    if (topNode == nullptr) {
        throw out_of_range("El historial esta vacio");
    }

    return topNode->data;
}

template <typename T>
int Stack<T>::getSize() {
    return size;
}

#endif // Stack_h