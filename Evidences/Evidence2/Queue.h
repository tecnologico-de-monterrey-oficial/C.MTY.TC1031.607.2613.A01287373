

// Carolina Vildósola Guzmán A01287373

#pragma once

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

    ~Queue() {
        while (head != nullptr) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }

    // enqueue
    void enqueue(T data) {
        Node<T>* nuevo = new Node<T>(data);

        if (head != nullptr) {
            tail->next = nuevo;
            tail = nuevo;
        } else {
            head = nuevo;
            tail = nuevo;
        }

        size++;
    }

    // dequeue
    T dequeue() {
        if (head == nullptr) {
            throw out_of_range("La fila esta vacia");
        }

        Node<T>* aux = head;
        T data = aux->data;

        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete aux;
        size--;

        return data;
    }

    // front
    T front() {
        if (head == nullptr) {
            throw out_of_range("La fila esta vacia");
        }

        return head->data;
    }

    // isEmpty
    bool isEmpty() {
        return head == nullptr;
    }

    // getSize
    int getSize() {
        return size;
    }

    // funciones con los nombres de tu actividad anterior
    void push(T data) {
        enqueue(data);
    }

    T pop() {
        return dequeue();
    }
};