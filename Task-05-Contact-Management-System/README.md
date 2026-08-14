# Contact Management System in C++

A CLI-based Contact Management application developed in C++ as part of the Workora C++ Programming Virtual Internship.

## Features

- Add, view, search, edit, and delete contacts
- Search contacts by name or phone number
- Store name, phone, email, and address
- Persistent storage using file I/O
- Load saved contacts when the program starts

## Concepts Used

- Classes and encapsulation
- Getters and setters
- `vector` for dynamic contact storage
- `ifstream` and `ofstream` for file handling
- Loops and switch-case logic
- Iterators for deleting contacts

## File Handling

Contact data is stored in:

```text
contacts.txt
```

The application saves contacts when they are added, edited, or deleted and loads them when the program starts.

## How to Run

### Compile

```bash
g++ contact_manager.cpp -o contact_manager.exe
```

### Execute

Windows:

```powershell
.\contact_manager.exe
```

## Menu Options

1. Add Contact
2. View Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit

## Internship

Developed as part of the **Workora C++ Programming Virtual Internship**.

**Intern ID:** WKR-JUL26TOAUG26-517