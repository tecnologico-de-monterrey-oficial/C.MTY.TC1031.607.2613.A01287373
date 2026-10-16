

// Carolina Vildósola Guzmán A01287373

#pragma once

#include "LinkedList.h"

using namespace std;

template <typename T>
class Stack {
private:
    LinkedList<T> list;

public:
    Stack() {}

    // push
    void push(T data) {
        list.push_front(data);
    }

    // pop
    T pop() {
        return list.pop_front();
    }

    // peek
    T peek() {
        return list.getFirst();
    }

    // top
    T top() {
        return peek();
    }

    // isEmpty
    bool isEmpty() {
        return list.getSize() == 0;
    }

    // getSize
    int getSize() {
        return list.getSize();
    }
};