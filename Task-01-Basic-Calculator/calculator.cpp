#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2, result;

    do {
        cout << "\n============================\n";
        cout << "      BASIC CALCULATOR\n";
        cout << "============================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exit\n";
        cout << "============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 6.\n";
            continue;
        }

        if (choice >= 1 && choice <= 5) {
            cout << "Enter first number: ";
            cin >> num1;

            cout << "Enter second number: ";
            cin >> num2;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid number entered.\n";
                continue;
            }
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;

            case 2:
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;

            case 3:
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;

            case 4:
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed.\n";
                } else {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                }
                break;

            case 5:
                if (static_cast<int>(num2) == 0) {
                    cout << "Error: Modulus by zero is not allowed.\n";
                } else {
                    result = static_cast<int>(num1) % static_cast<int>(num2);
                    cout << "Result: " << result << endl;
                }
                break;

            case 6:
                cout << "Calculator closed. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}