#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class MediaItem {
protected:
    int id;
    string title;
    bool checkedOut;

public:
    MediaItem(int itemId, string itemTitle, bool status = false)
        : id(itemId), title(itemTitle), checkedOut(status) {}

    virtual ~MediaItem() = default;

    int getId() const {
        return id;
    }

    string getTitle() const {
        return title;
    }

    bool isCheckedOut() const {
        return checkedOut;
    }

    virtual string getType() const = 0;

    virtual double calculateFine(int days) const = 0;

    virtual void display() const {
        cout << "ID: " << id
             << " | Type: " << getType()
             << " | Title: " << title
             << " | Status: "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;
    }

    void checkout() {
        if (checkedOut) {
            cout << "Item is already checked out.\n";
            return;
        }

        checkedOut = true;
        cout << "Item checked out successfully.\n";
    }

    void returnItem(int days) {
        if (!checkedOut) {
            cout << "Item is not currently checked out.\n";
            return;
        }

        checkedOut = false;

        double fine = calculateFine(days);

        cout << "Item returned successfully.\n";

        if (fine > 0) {
            cout << "Overdue fine: Rs." << fine << endl;
        } else {
            cout << "No overdue fine.\n";
        }
    }
};

class Book : public MediaItem {
public:
    Book(int itemId, string itemTitle, bool status = false)
        : MediaItem(itemId, itemTitle, status) {}

    string getType() const override {
        return "Book";
    }

    double calculateFine(int days) const override {
        const int allowedDays = 14;
        const double finePerDay = 5.0;

        if (days <= allowedDays) {
            return 0;
        }

        return (days - allowedDays) * finePerDay;
    }
};

class Journal : public MediaItem {
public:
    Journal(int itemId, string itemTitle, bool status = false)
        : MediaItem(itemId, itemTitle, status) {}

    string getType() const override {
        return "Journal";
    }

    double calculateFine(int days) const override {
        const int allowedDays = 7;
        const double finePerDay = 10.0;

        if (days <= allowedDays) {
            return 0;
        }

        return (days - allowedDays) * finePerDay;
    }
};

class Library {
private:
    vector<unique_ptr<MediaItem>> catalog;
    const string filename = "library.txt";

public:
    Library() {
        loadCatalog();
    }

    void displayCatalog() const {
        if (catalog.empty()) {
            cout << "\nLibrary catalog is empty.\n";
            return;
        }

        cout << "\n========================================\n";
        cout << "             LIBRARY CATALOG\n";
        cout << "========================================\n";

        for (const auto& item : catalog) {
            item->display();
        }
    }

    void addBook() {
        int id;
        string title;

        cout << "\nEnter Book ID: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid ID. Please enter a number.\n";
            return;
        }

    if (findItem(id) != nullptr) {
        cout << "Error: An item with this ID already exists.\n";
        return;
    }

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        if (title.empty()) {
            cout << "Error: Title cannot be empty.\n";
            return;
        }

        catalog.push_back(
            make_unique<Book>(id, title)
        );

        saveCatalog();

        cout << "Book added successfully.\n";
    }

        void addJournal() {
        int id;
        string title;

        cout << "\nEnter Journal ID: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid ID. Please enter a number.\n";
            return;
        }

        if (findItem(id) != nullptr) {
            cout << "Error: An item with this ID already exists.\n";
            return;
        }

        cin.ignore();

        cout << "Enter Journal Title: ";
        getline(cin, title);

        if (title.empty()) {
            cout << "Error: Title cannot be empty.\n";
            return;
        }

        catalog.push_back(
            make_unique<Journal>(id, title)
        );

        saveCatalog();

        cout << "Journal added successfully.\n";
    }
    MediaItem* findItem(int id) const {
        for (const auto& item : catalog) {
            if (item->getId() == id) {
                return item.get();
            }
        }

        return nullptr;
    }

    void checkoutItem() {
    int id;

    cout << "\nEnter Item ID to checkout: ";
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID. Please enter a number.\n";
        return;
    }

    MediaItem* item = findItem(id);

    if (item == nullptr) {
        cout << "Item not found.\n";
        return;
    }

    item->checkout();
    saveCatalog();
    }

    void returnItem() {
    int id;
    int days;

    cout << "\nEnter Item ID to return: ";
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID. Please enter a number.\n";
        return;
    }

    MediaItem* item = findItem(id);

    if (item == nullptr) {
        cout << "Item not found.\n";
        return;
    }

    if (!item->isCheckedOut()) {
        cout << "Item is not currently checked out.\n";
        return;
    }

    cout << "Enter number of days item was kept: ";
    cin >> days;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid number of days.\n";
        return;
    }

    if (days < 0) {
        cout << "Invalid number of days.\n";
        return;
    }

    item->returnItem(days);
    saveCatalog();
    }

    void searchItem() const {
        string searchTitle;

        cin.ignore();

        cout << "\nEnter title to search: ";
        getline(cin, searchTitle);

        bool found = false;

        for (const auto& item : catalog) {
            if (item->getTitle() == searchTitle) {
                item->display();
                found = true;
            }
        }

        if (!found) {
            cout << "Item not found.\n";
        }
    }

    void saveCatalog() const {
        ofstream file(filename);

        if (!file) {
            cout << "Error: Unable to save catalog.\n";
            return;
        }

        for (const auto& item : catalog) {
            file << item->getType() << "|"
                 << item->getId() << "|"
                 << item->getTitle() << "|"
                 << item->isCheckedOut() << "\n";
        }
    }

    void loadCatalog() {
        ifstream file(filename);

        if (!file) {
            return;
        }

        string type;
        int id;
        string title;
        bool checkedOut;
        char separator;

        while (getline(file, type, '|')) {
            file >> id >> separator;
            getline(file, title, '|');
            file >> checkedOut;
            file.ignore();

            if (type == "Book") {
                catalog.push_back(
                    make_unique<Book>(id, title, checkedOut)
                );
            }
            else if (type == "Journal") {
                catalog.push_back(
                    make_unique<Journal>(id, title, checkedOut)
                );
            }
        }
    }
};

int main() {
    Library library;

    int choice;

    do {
        cout << "\n========================================\n";
        cout << "        LIBRARY MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. View Catalog\n";
        cout << "2. Add Book\n";
        cout << "3. Add Journal\n";
        cout << "4. Checkout Item\n";
        cout << "5. Return Item\n";
        cout << "6. Search Item\n";
        cout << "7. Save & Exit\n";
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
                library.displayCatalog();
                break;

            case 2:
                library.addBook();
                break;

            case 3:
                library.addJournal();
                break;

            case 4:
                library.checkoutItem();
                break;

            case 5:
                library.returnItem();
                break;

            case 6:
                library.searchItem();
                break;

            case 7:
                cout << "\nCatalog saved. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select 1-7.\n";
        }

    } while (choice != 7);

    return 0;
}