
// Carolina Vildósola Guzmán A01287373

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <queue>
#include "NodeT.h"

using namespace std;

template <typename T>
class BST {
private:
    NodeT<T>* root;

    void printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot);

    void preorder(NodeT<T>* node);
    void inorder(NodeT<T>* node);
    void postorder(NodeT<T>* node);

    int getHeight(NodeT<T>* node);
    NodeT<T>* deleteNode(NodeT<T>* node, T data);
    void clear(NodeT<T>* node);

public:
    BST();
    ~BST();

    void insert(T data);
    void remove(T data);
    void print();
    bool find(T data);
    void visit(int option);
    int height();
    void ancestors(T data);
    int whatLevelAmI(T data);
};

// constructor
template <typename T>
BST<T>::BST() {
    root = nullptr;
}

// destructor para liberar los nodos
template <typename T>
BST<T>::~BST() {
    clear(root);
}

template <typename T>
void BST<T>::clear(NodeT<T>* node) {
    if (node == nullptr) {
        return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
}

// insertar un dato
template <typename T>
void BST<T>::insert(T data) {

    // si esta vacio, el nuevo nodo es la raiz
    if (root == nullptr) {
        root = new NodeT<T>(data);
        return;
    }

    NodeT<T>* aux = root;
    NodeT<T>* father = nullptr;

    // buscamos donde debe ir el dato
    while (aux != nullptr) {
        father = aux;

        // no insertamos datos repetidos
        if (data == aux->data) {
            return;
        }

        if (data < aux->data) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }

    // insertamos a la izquierda o derecha
    if (data < father->data) {
        father->left = new NodeT<T>(data);
    } else {
        father->right = new NodeT<T>(data);
    }
}

// eliminar un nodo
template <typename T>
NodeT<T>* BST<T>::deleteNode(NodeT<T>* node, T data) {

    if (node == nullptr) {
        return nullptr;
    }

    // buscamos el dato
    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {

        // si no tiene hijo izquierdo
        if (node->left == nullptr) {
            NodeT<T>* temp = node->right;
            delete node;
            return temp;
        }

        // si no tiene hijo derecho
        if (node->right == nullptr) {
            NodeT<T>* temp = node->left;
            delete node;
            return temp;
        }

        // si tiene dos hijos, buscamos el menor del lado derecho
        NodeT<T>* temp = node->right;

        while (temp->left != nullptr) {
            temp = temp->left;
        }

        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

template <typename T>
void BST<T>::remove(T data) {
    root = deleteNode(root, data);
}

// imprimir el arbol
template <typename T>
void BST<T>::printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot) {

    if (node == nullptr) {
        return;
    }

    printTree(node->right,
              prefix + (isRoot ? "" : (isRight ? "      " : "|     ")),
              true, false);

    cout << prefix
         << (isRoot ? "" : (isRight ? ".---- " : "`---- "))
         << node->data << endl;

    printTree(node->left,
              prefix + (isRoot ? "" : (isRight ? "|     " : "      ")),
              false, false);
}

template <typename T>
void BST<T>::print() {
    if (root == nullptr) {
        cout << "Arbol vacio" << endl;
        return;
    }

    printTree(root, "", false, true);
}

// buscar un dato
template <typename T>
bool BST<T>::find(T data) {

    NodeT<T>* aux = root;

    while (aux != nullptr) {

        if (data == aux->data) {
            return true;
        }

        if (data < aux->data) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }

    return false;
}

// preorder: raiz, izquierda, derecha
template <typename T>
void BST<T>::preorder(NodeT<T>* node) {
    if (node == nullptr) {
        return;
    }

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// inorder: izquierda, raiz, derecha
template <typename T>
void BST<T>::inorder(NodeT<T>* node) {
    if (node == nullptr) {
        return;
    }

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// postorder: izquierda, derecha, raiz
template <typename T>
void BST<T>::postorder(NodeT<T>* node) {
    if (node == nullptr) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

// mostrar recorridos
template <typename T>
void BST<T>::visit(int option) {

    if (root == nullptr) {
        cout << "El arbol esta vacio" << endl;
        return;
    }

    switch (option) {
        case 1:
            cout << "Preorder: ";
            preorder(root);
            break;

        case 2:
            cout << "Inorder: ";
            inorder(root);
            break;

        case 3:
            cout << "Postorder: ";
            postorder(root);
            break;

        case 4: {
            cout << "Por niveles: ";

            queue<NodeT<T>*> fila;
            fila.push(root);

            // sacamos un nodo y agregamos sus hijos
            while (!fila.empty()) {
                NodeT<T>* aux = fila.front();
                fila.pop();

                cout << aux->data << " ";

                if (aux->left != nullptr) {
                    fila.push(aux->left);
                }

                if (aux->right != nullptr) {
                    fila.push(aux->right);
                }
            }
            break;
        }

        default:
            cout << "Opcion invalida";
            break;
    }

    cout << endl;
}

// calcular la altura
template <typename T>
int BST<T>::getHeight(NodeT<T>* node) {

    if (node == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    // tomamos la altura mayor y sumamos el nodo actual
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

template <typename T>
int BST<T>::height() {
    return getHeight(root);
}

// mostrar los ancestros de un dato
template <typename T>
void BST<T>::ancestors(T data) {

    if (!find(data)) {
        cout << "El dato no existe en el arbol" << endl;
        return;
    }

    NodeT<T>* aux = root;

    if (aux->data == data) {
        cout << "La raiz no tiene ancestros" << endl;
        return;
    }

    cout << "Ancestros de " << data << ": ";

    // mostramos los nodos por los que pasamos
    while (aux != nullptr && aux->data != data) {
        cout << aux->data << " ";

        if (data < aux->data) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }

    cout << endl;
}

// buscar en que nivel esta un dato
template <typename T>
int BST<T>::whatLevelAmI(T data) {

    NodeT<T>* aux = root;
    int level = 0;

    while (aux != nullptr) {

        if (aux->data == data) {
            return level;
        }

        if (data < aux->data) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }

        level++;
    }

    return -1;
}

#endif
