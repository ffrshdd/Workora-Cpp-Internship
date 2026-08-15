#include <iostream>
#include "bst.hpp"

using namespace std;

int main() {
    cout << "========================================\n";
    cout << "       BINARY SEARCH TREE\n";
    cout << "========================================\n";

    BST<int> tree;

    cout << "\nInserting values:\n";

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int value : values) {
        cout << "Insert: " << value << endl;
        tree.insert(value);
    }

    cout << "\n========================================\n";
    cout << "             TRAVERSALS\n";
    cout << "========================================\n";

    cout << "In-Order:   ";
    tree.inOrder();

    cout << "Pre-Order:  ";
    tree.preOrder();

    cout << "Post-Order: ";
    tree.postOrder();

    cout << "\n========================================\n";
    cout << "               SEARCH\n";
    cout << "========================================\n";

    int searchValue = 40;

    cout << "Searching for " << searchValue << ": ";

    if (tree.search(searchValue)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    searchValue = 90;

    cout << "Searching for " << searchValue << ": ";

    if (tree.search(searchValue)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "\n========================================\n";
    cout << "               DELETION\n";
    cout << "========================================\n";

    cout << "Deleting 20 (leaf node)...\n";
    tree.remove(20);

    cout << "In-Order after deletion: ";
    tree.inOrder();

    cout << "\nDeleting 30 (node with one child)...\n";
    tree.remove(30);

    cout << "In-Order after deletion: ";
    tree.inOrder();

    cout << "\nDeleting 50 (node with two children)...\n";
    tree.remove(50);

    cout << "In-Order after deletion: ";
    tree.inOrder();

    cout << "\n========================================\n";
    cout << "           MEMORY CLEANUP\n";
    cout << "========================================\n";
    cout << "BST destructor will release all remaining nodes.\n";

    cout << "\nProgram completed successfully.\n";

    return 0;
}