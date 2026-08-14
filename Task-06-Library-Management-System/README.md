# Library Management System in C++

A console-based Library Management System developed in C++ as part of the Workora C++ Programming Virtual Internship.

## Features

- Add books and journals
- View the library catalog
- Search items by title
- Checkout and return items
- Prevent double checkout
- Calculate overdue fines
- Persist catalog data using file handling
- Restore catalog data when the program starts

## OOP Concepts Used

- Inheritance
- Polymorphism
- Abstract base class
- Virtual functions
- Function overriding
- Encapsulation
- Constructors
- Smart pointers using `unique_ptr`

## Class Structure

```text
MediaItem
├── Book
└── Journal
```

`MediaItem` is the base class, while `Book` and `Journal` derive from it and implement their own fine calculation behavior.

## Memory Management

The catalog uses:

```cpp
vector<unique_ptr<MediaItem>>
```

Smart pointers provide automatic memory management and avoid manual `new` and `delete` operations.

## Fine Calculation

### Books

- Allowed period: 14 days
- Fine: Rs.5 per overdue day

### Journals

- Allowed period: 7 days
- Fine: Rs.10 per overdue day

## File Persistence

The catalog is stored in:

```text
library.txt
```

The application loads saved items when it starts and saves catalog changes during operation.

## Menu Options

1. View Catalog
2. Add Book
3. Add Journal
4. Checkout Item
5. Return Item
6. Search Item
7. Save & Exit

## How to Run

### Compile

```bash
g++ library_management.cpp -o library_management.exe
```

### Execute

Windows:

```powershell
.\library_management.exe
```

## Technologies Used

- C++
- iostream
- fstream
- vector
- memory
- string

## Internship

Developed as part of the **Workora C++ Programming Virtual Internship**.

**Intern ID:** WKR-JUL26TOAUG26-517