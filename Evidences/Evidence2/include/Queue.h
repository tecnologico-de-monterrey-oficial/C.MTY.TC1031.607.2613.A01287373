

// Carolina Vildósola Guzmán A01287373

#pragma once

#include "LinkedList.h"

using namespace std;

template <typename T>
class Queue {
private:
    LinkedList<T> list;

public:
    Queue() {}

    // enqueue
    void enqueue(T data) {
        list.push_back(data);
    }

    // dequeue
    T dequeue() {
        return list.pop_front();
    }

    // front
    T front() {
        return list.getFirst();
    }

    // isEmpty
    bool isEmpty() {
        return list.getSize() == 0;
    }

    // getSize
    int getSize() {
        return list.getSize();
    }

    // funciones de tu actividad anterior
    void push(T data) {
        enqueue(data);
    }

    T pop() {
        return dequeue();
    }
};