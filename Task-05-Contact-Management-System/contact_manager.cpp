#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:
    string name;
    string phone;
    string email;
    string address;

public:
    Contact(string contactName, string contactPhone,
            string contactEmail, string contactAddress)
        : name(contactName),
          phone(contactPhone),
          email(contactEmail),
          address(contactAddress) {}

    string getName() const {
        return name;
    }

    string getPhone() const {
        return phone;
    }

    string getEmail() const {
        return email;
    }

    string getAddress() const {
        return address;
    }

    void setName(string newName) {
        name = newName;
    }

    void setPhone(string newPhone) {
        phone = newPhone;
    }

    void setEmail(string newEmail) {
        email = newEmail;
    }

    void setAddress(string newAddress) {
        address = newAddress;
    }

    void display() const {
        cout << "\nName    : " << name << endl;
        cout << "Phone   : " << phone << endl;
        cout << "Email   : " << email << endl;
        cout << "Address : " << address << endl;
    }
};

class ContactManager {
private:
    vector<Contact> contacts;
    const string filename = "contacts.txt";

public:
    ContactManager() {
        loadContacts();
    }

    void addContact() {
        string name, phone, email, address;

        cin.ignore();

        cout << "\nEnter name: ";
        getline(cin, name);

        cout << "Enter phone: ";
        getline(cin, phone);

        cout << "Enter email: ";
        getline(cin, email);

        cout << "Enter address: ";
        getline(cin, address);

        contacts.push_back(
            Contact(name, phone, email, address)
        );

        saveContacts();

        cout << "\nContact added successfully!\n";
    }

    void displayContacts() const {
        if (contacts.empty()) {
            cout << "\nNo contacts found.\n";
            return;
        }

        cout << "\n========================================\n";
        cout << "             CONTACT LIST\n";
        cout << "========================================\n";

        for (size_t i = 0; i < contacts.size(); i++) {
            cout << "\nContact #" << i + 1;
            contacts[i].display();
        }
    }

    void searchContact() const {
        int choice;

        cout << "\nSearch Contact By:\n";
        cout << "1. Name\n";
        cout << "2. Phone\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        string searchValue;
        bool found = false;

        if (choice == 1) {
            cout << "Enter name: ";
            getline(cin, searchValue);

            for (const Contact& contact : contacts) {
                if (contact.getName() == searchValue) {
                    contact.display();
                    found = true;
                }
            }
        }
        else if (choice == 2) {
            cout << "Enter phone: ";
            getline(cin, searchValue);

            for (const Contact& contact : contacts) {
                if (contact.getPhone() == searchValue) {
                    contact.display();
                    found = true;
                }
            }
        }
        else {
            cout << "Invalid search choice.\n";
            return;
        }

        if (!found) {
            cout << "\nContact not found.\n";
        }
    }

    void editContact() {
        string searchPhone;

        cin.ignore();

        cout << "\nEnter phone number of contact to edit: ";
        getline(cin, searchPhone);

        for (Contact& contact : contacts) {
            if (contact.getPhone() == searchPhone) {

                string value;

                cout << "\nContact found.\n";

                cout << "Enter new name: ";
                getline(cin, value);
                contact.setName(value);

                cout << "Enter new phone: ";
                getline(cin, value);
                contact.setPhone(value);

                cout << "Enter new email: ";
                getline(cin, value);
                contact.setEmail(value);

                cout << "Enter new address: ";
                getline(cin, value);
                contact.setAddress(value);

                saveContacts();

                cout << "\nContact updated successfully!\n";
                return;
            }
        }

        cout << "\nContact not found.\n";
    }

    void deleteContact() {
        string searchPhone;

        cin.ignore();

        cout << "\nEnter phone number of contact to delete: ";
        getline(cin, searchPhone);

        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getPhone() == searchPhone) {
                contacts.erase(it);
                saveContacts();

                cout << "\nContact deleted successfully!\n";
                return;
            }
        }

        cout << "\nContact not found.\n";
    }

    void saveContacts() const {
        ofstream file(filename);

        for (const Contact& contact : contacts) {
            file << contact.getName() << "|"
                 << contact.getPhone() << "|"
                 << contact.getEmail() << "|"
                 << contact.getAddress() << "\n";
        }
    }

    void loadContacts() {
        ifstream file(filename);

        if (!file) {
            return;
        }

        string name, phone, email, address;

        while (getline(file, name, '|') &&
               getline(file, phone, '|') &&
               getline(file, email, '|') &&
               getline(file, address)) {

            contacts.push_back(
                Contact(name, phone, email, address)
            );
        }
    }
};

int main() {
    ContactManager manager;

    int choice;

    do {
        cout << "\n========================================\n";
        cout << "       CONTACT MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
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
                manager.addContact();
                break;

            case 2:
                manager.displayContacts();
                break;

            case 3:
                manager.searchContact();
                break;

            case 4:
                manager.editContact();
                break;

            case 5:
                manager.deleteContact();
                break;

            case 6:
                cout << "\nExiting... Contacts saved.\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}