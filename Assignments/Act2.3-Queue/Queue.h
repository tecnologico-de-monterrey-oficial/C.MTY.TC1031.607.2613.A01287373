
// Carolina Vildósola Guzmán
// A01287373

#ifndef Queue_h
#define Queue_h

#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    T pop();
    void push(T data);
    T front();
    int getSize();
};

template <typename T>
void Queue<T>::push(T data) {
    if (head != nullptr) {
        tail->next = new Node<T>(data);
        tail = tail->next;
    } else {
        head = new Node<T>(data);
        tail = head;
    }

    size++;
}

template <typename T>
T Queue<T>::pop() {
    if (head == nullptr) {
        throw out_of_range("La fila esta vacia");
    }

    Node<T>* aux = head;
    T data = aux->data;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
    }

    delete aux;
    size--;

    return data;
}

template <typename T>
T Queue<T>::front() {
    if (head == nullptr) {
        throw out_of_range("La fila esta vacia");
    }

    return head->data;
}

template <typename T>
int Queue<T>::getSize() {
    return size;
}

#endif // Queue_h