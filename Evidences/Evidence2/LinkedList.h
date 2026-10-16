

// Carolina Vildósola Guzmán A01287373

#pragma once

#include <iostream>
#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }

    // push_front
    void push_front(T data) {
        Node<T>* nuevo = new Node<T>(data);
        nuevo->next = head;
        head = nuevo;

        // si estaba vacia, tambien es el ultimo
        if (tail == nullptr) {
            tail = nuevo;
        }

        size++;
    }

    // push_back
    void push_back(T data) {
        Node<T>* nuevo = new Node<T>(data);

        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            tail->next = nuevo;
            tail = nuevo;
        }

        size++;
    }

    // pop_front
    T pop_front() {
        if (head == nullptr) {
            throw out_of_range("La lista esta vacia");
        }

        Node<T>* aux = head;
        T data = aux->data;

        head = head->next;
        delete aux;

        if (head == nullptr) {
            tail = nullptr;
        }

        size--;
        return data;
    }

    // getSize
    int getSize() {
        return size;
    }

    // print
    void print() {
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
};