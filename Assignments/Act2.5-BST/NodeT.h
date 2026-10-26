

// Carolina Vildósola Guzmán A01287373

#ifndef NODET_H
#define NODET_H

template <typename T>
struct NodeT {
    T data;
    NodeT<T>* left;
    NodeT<T>* right;

    // creamos el nodo con su dato
    // al principio no tiene hijos
    NodeT(const T& value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

#endif
