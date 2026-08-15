#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value)
            : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const T& value);
    bool search(Node* node, const T& value) const;
    Node* remove(Node* node, const T& value);
    Node* findMin(Node* node) const;

    void inOrder(Node* node) const;
    void preOrder(Node* node) const;
    void postOrder(Node* node) const;

    void destroyTree(Node* node);

public:
    BST();
    ~BST();

    void insert(const T& value);
    bool search(const T& value) const;
    void remove(const T& value);

    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template <typename T>
typename BST<T>::Node* BST<T>::insert(Node* node, const T& value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    else {
        cout << "Duplicate value ignored: " << value << endl;
    }

    return node;
}

template <typename T>
void BST<T>::insert(const T& value) {
    root = insert(root, value);
}

template <typename T>
bool BST<T>::search(Node* node, const T& value) const {
    if (node == nullptr) {
        return false;
    }

    if (value == node->data) {
        return true;
    }

    if (value < node->data) {
        return search(node->left, value);
    }

    return search(node->right, value);
}

template <typename T>
bool BST<T>::search(const T& value) const {
    return search(root, value);
}

template <typename T>
typename BST<T>::Node* BST<T>::findMin(Node* node) const {
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }

    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::remove(Node* node, const T& value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    }
    else if (value > node->data) {
        node->right = remove(node->right, value);
    }
    else {
        // Case 1: No children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        // Case 2: Only right child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        // Case 3: Only left child
        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 4: Two children
        Node* successor = findMin(node->right);
        node->data = successor->data;
        node->right = remove(node->right, successor->data);
    }

    return node;
}

template <typename T>
void BST<T>::remove(const T& value) {
    if (!search(value)) {
        cout << "Value not found: " << value << endl;
        return;
    }

    root = remove(root, value);
    cout << "Deleted: " << value << endl;
}

template <typename T>
void BST<T>::inOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

template <typename T>
void BST<T>::inOrder() const {
    inOrder(root);
    cout << endl;
}

template <typename T>
void BST<T>::preOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void BST<T>::preOrder() const {
    preOrder(root);
    cout << endl;
}

template <typename T>
void BST<T>::postOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

template <typename T>
void BST<T>::postOrder() const {
    postOrder(root);
    cout << endl;
}

template <typename T>
void BST<T>::destroyTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

#endif