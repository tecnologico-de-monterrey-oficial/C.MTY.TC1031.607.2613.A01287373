
#ifndef List_h
#define List_h

#include <vector>
#include <iostream>

template <typename T>
class List {
private:
    std::vector<T> data;
    int size;
public:
    List();
    void insert(T value);
    int getSize();
    T getData(int pos);
    void removeLast();
    T getMax();
    void print();
    void removeAt(int pos);

    void insertAt(int pos, T value);
};

template <typename T>
List<T>::List() {
    size = 0;
}

template <typename T>
void List<T>::insert(T value) {
    data.push_back(value);
    size++;
}

template <typename T>
int List<T>::getSize() {
    return size;
}
template <typename T>
T List<T>::getData(int pos) {
    return data[pos];
}

template <typename T>
void List<T>::removeLast() {
    if (size > 0) {
        std::cout << data[size - 1] << std::endl;
        data.pop_back();
        size--;
    }
    else {
        std::cout << "NO HAY ELEMENTOS" << std::endl;
    }
}
template <typename T>
T List<T>::getMax() {
    T max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}
template <typename T>
void List<T>::print() {
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "] - " << data[i] << std::endl;
    }
}

template <typename T>
void List<T>::insertAt(int pos, T value) {
    if (pos >= 0 && pos <= size) {
         data.insert(data.begin() + pos, value);
        size++;
    }
    else {
    std::cout << "POSICIÓN INVÁLIDA" << std::endl;
}
}    
template <typename T>
void List<T>::removeAt(int pos) {
     if (size == 0) {
        std::cout << "NO HAY ELEMENTOS" << std::endl;
}
else if (pos < 0 || pos >= size) {
        std::cout << "POSICIÓN INVÁLIDA" << std::endl;
}     
else {
    std::cout << data[pos] << std::endl;
    data.erase(data.begin() + pos);
    size--;
}
}
        



#endif /* List_h */