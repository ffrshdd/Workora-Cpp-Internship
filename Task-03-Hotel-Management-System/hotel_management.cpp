#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Room {
private:
    int roomNumber;
    string type;
    double price;
    bool booked;

public:
    Room(int number, string roomType, double roomPrice, bool roomBooked = false)
        : roomNumber(number),
          type(roomType),
          price(roomPrice),
          booked(roomBooked) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    string getType() const {
        return type;
    }

    double getPrice() const {
        return price;
    }

    bool isBooked() const {
        return booked;
    }

    void bookRoom() {
        booked = true;
    }

    void checkoutRoom() {
        booked = false;
    }

    void displayRoom() const {
        cout << "Room: " << roomNumber
             << " | Type: " << type
             << " | Price: Rs." << price
             << " | Status: " << (booked ? "Booked" : "Available")
             << endl;
    }
};

class Customer {
private:
    string name;
    string phone;
    int roomNumber;

public:
    Customer(string customerName, string customerPhone, int room)
        : name(customerName),
          phone(customerPhone),
          roomNumber(room) {}

    string getName() const {
        return name;
    }

    string getPhone() const {
        return phone;
    }

    int getRoomNumber() const {
        return roomNumber;
    }

    void displayCustomer() const {
        cout << "Name: " << name
             << " | Phone: " << phone
             << " | Room: " << roomNumber
             << endl;
    }
};

class HotelManagementSystem {
private:
    vector<Room> rooms;
    vector<Customer> customers;

    const string roomFile = "rooms.txt";
    const string customerFile = "customers.txt";

public:
    HotelManagementSystem() {
        initializeRooms();
        loadData();
    }

    void initializeRooms() {
        if (rooms.empty()) {
            rooms.push_back(Room(101, "Single", 1500));
            rooms.push_back(Room(102, "Single", 1500));
            rooms.push_back(Room(103, "Double", 2500));
            rooms.push_back(Room(104, "Double", 2500));
            rooms.push_back(Room(105, "Suite", 4000));
        }
    }

    void displayRooms() const {
        cout << "\n========================================\n";
        cout << "              ROOM LIST\n";
        cout << "========================================\n";

        for (const Room& room : rooms) {
            room.displayRoom();
        }
    }

    void bookRoom() {
        int roomNumber;
        string name;
        string phone;

        cout << "\nEnter room number: ";
        cin >> roomNumber;

        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {

                if (room.isBooked()) {
                    cout << "Error: Room " << roomNumber
                         << " is already booked.\n";
                    return;
                }

                cin.ignore();

                cout << "Enter customer name: ";
                getline(cin, name);

                cout << "Enter customer phone: ";
                getline(cin, phone);

                room.bookRoom();
                customers.push_back(Customer(name, phone, roomNumber));

                saveData();

                cout << "\nRoom booked successfully!\n";
                cout << "Customer: " << name << endl;
                cout << "Room: " << roomNumber << endl;

                return;
            }
        }

        cout << "Error: Room " << roomNumber << " does not exist.\n";
    }

    void checkout() {
        int roomNumber;

        cout << "\nEnter room number for checkout: ";
        cin >> roomNumber;

        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {

                if (!room.isBooked()) {
                    cout << "Room " << roomNumber
                         << " is already available.\n";
                    return;
                }

                room.checkoutRoom();

                for (auto it = customers.begin(); it != customers.end(); ++it) {
                    if (it->getRoomNumber() == roomNumber) {
                        customers.erase(it);
                        break;
                    }
                }

                saveData();

                cout << "Checkout completed successfully.\n";
                return;
            }
        }

        cout << "Error: Room " << roomNumber << " does not exist.\n";
    }

    void searchCustomer() const {
        int choice;

        cout << "\nSearch Customer By:\n";
        cout << "1. Name\n";
        cout << "2. Phone\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {
            string name;

            cout << "Enter customer name: ";
            getline(cin, name);

            bool found = false;

            for (const Customer& customer : customers) {
                if (customer.getName() == name) {
                    customer.displayCustomer();
                    found = true;
                }
            }

            if (!found) {
                cout << "Customer not found.\n";
            }
        }
        else if (choice == 2) {
            string phone;

            cout << "Enter customer phone: ";
            getline(cin, phone);

            bool found = false;

            for (const Customer& customer : customers) {
                if (customer.getPhone() == phone) {
                    customer.displayCustomer();
                    found = true;
                }
            }

            if (!found) {
                cout << "Customer not found.\n";
            }
        }
        else {
            cout << "Invalid search choice.\n";
        }
    }

    void saveData() const {
        ofstream roomOut(roomFile);
        ofstream customerOut(customerFile);

        for (const Room& room : rooms) {
            roomOut << room.getRoomNumber() << "|"
                    << room.getType() << "|"
                    << room.getPrice() << "|"
                    << room.isBooked() << "\n";
        }

        for (const Customer& customer : customers) {
            customerOut << customer.getName() << "|"
                        << customer.getPhone() << "|"
                        << customer.getRoomNumber() << "\n";
        }
    }

    void loadData() {
        ifstream roomIn(roomFile);
        ifstream customerIn(customerFile);

        if (roomIn) {
            rooms.clear();

            int number;
            string type;
            double price;
            bool booked;
            char separator;

            while (roomIn >> number >> separator) {
                getline(roomIn, type, '|');
                roomIn >> price >> separator >> booked;

                rooms.push_back(Room(number, type, price, booked));
            }
        }

        if (customerIn) {
            string name;
            string phone;
            int roomNumber;

            while (getline(customerIn, name, '|') &&
                   getline(customerIn, phone, '|') &&
                   (customerIn >> roomNumber)) {

                customerIn.ignore();

                customers.push_back(
                    Customer(name, phone, roomNumber)
                );
            }
        }
    }
};

int main() {
    HotelManagementSystem hotel;

    int choice;

    do {
        cout << "\n========================================\n";
        cout << "       HOTEL MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. View Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Checkout\n";
        cout << "4. Search Customer\n";
        cout << "5. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;

            case 2:
                hotel.bookRoom();
                break;

            case 3:
                hotel.checkout();
                break;

            case 4:
                hotel.searchCustomer();
                break;

            case 5:
                cout << "Thank you for using the Hotel Management System.\n";
                break;

            default:
                cout << "Invalid choice. Please select 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}