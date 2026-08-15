# Binary Search Tree in C++

A custom template-based Binary Search Tree implementation developed in C++ as part of the Workora C++ Programming Virtual Internship.

## Features

- Template-based Binary Search Tree
- Node insertion
- Node searching
- Node deletion
- In-Order traversal
- Pre-Order traversal
- Post-Order traversal
- Recursive tree operations
- Automatic memory cleanup using a destructor
- Duplicate value handling

## Data Structure

Each BST node contains:

- Data value
- Pointer to the left child
- Pointer to the right child

The tree maintains the Binary Search Tree property:

- Values smaller than a node are stored in the left subtree
- Values larger than a node are stored in the right subtree

## Operations Implemented

### Insert

Adds a new value to the correct position in the BST.

### Search

Recursively searches for a specified value.

### Delete

Supports deletion of:

- Leaf nodes
- Nodes with one child
- Nodes with two children

For nodes with two children, the in-order successor is used.

## Tree Traversals

The implementation supports:

```text
In-Order
Pre-Order
Post-Order
```

For the test tree:

```text
        50
       /  \
     30    70
    /  \   / \
   20  40 60 80
```

The traversals are:

```text
In-Order:   20 30 40 50 60 70 80
Pre-Order:  50 30 20 40 70 60 80
Post-Order: 20 40 30 60 80 70 50
```

## Memory Management

The BST dynamically allocates nodes using pointers.

The destructor recursively traverses the entire tree and deletes every remaining node to prevent memory leaks.

## Files

```text
bst.hpp
```

Contains the template-based BST class and its implementation.

```text
bst.cpp
```

Contains the demonstration program and test cases.

## How to Run

### Compile

```bash
g++ bst.cpp -o bst.exe
```

### Execute

Windows:

```powershell
.\bst.exe
```

## Technologies Used

- C++
- Templates
- Pointers
- Recursion
- Dynamic memory allocation
- Object-oriented programming

## Internship

Developed as part of the **Workora C++ Programming Virtual Internship**.

**Intern ID:** WKR-JUL26TOAUG26-517