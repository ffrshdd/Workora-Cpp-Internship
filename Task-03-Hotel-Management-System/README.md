# Hotel Management System in C++

An Object-Oriented Hotel Management System developed in C++ as part of the Workora C++ Programming Virtual Internship.

## Features

- View available and booked rooms
- Book hotel rooms
- Prevent double booking
- Store customer information
- Search customers by name or phone
- Checkout customers
- Persist room and customer data using files
- Restore booking information when the program starts

## OOP Concepts Used

- Classes and objects
- Encapsulation
- Constructors
- Private data members
- Public member functions
- Vector-based collections

## File Handling

The application uses C++ file streams to permanently store data:

- `rooms.txt` - stores room information and booking status
- `customers.txt` - stores customer information and assigned rooms

## Technologies Used

- C++
- iostream
- fstream
- vector
- string

## How to Run

### Compile

```bash
g++ hotel_management.cpp -o hotel_management
### Execute

Windows:

```powershell
.\hotel_management.exe
```

## Main Operations

1. View Rooms
2. Book Room
3. Checkout
4. Search Customer
5. Exit

## Internship

Developed as part of the **Workora C++ Programming Virtual Internship**.

**Intern ID:** WKR-JUL26TOAUG26-517