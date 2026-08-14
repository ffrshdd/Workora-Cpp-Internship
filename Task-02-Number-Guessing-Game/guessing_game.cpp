#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int guess;
    int attempts;
    char replay;

    // Seed the random number generator
    srand(time(0));

    cout << "====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "====================================\n";

    do {
        int target = rand() % 100 + 1;
        attempts = 0;

        cout << "\nI have selected a number between 1 and 100.\n";
        cout << "Try to guess it!\n";

        do {
            cout << "\nEnter your guess: ";
            cin >> guess;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            attempts++;

            if (guess > target) {
                cout << "Too High! Try again.\n";
            }
            else if (guess < target) {
                cout << "Too Low! Try again.\n";
            }
            else {
                cout << "\nCongratulations! You guessed the number.\n";
                cout << "Number: " << target << endl;
                cout << "Attempts: " << attempts << endl;

                // Simple score based on attempts
                int score = 100 - ((attempts - 1) * 10);

                if (score < 10) {
                    score = 10;
                }

                cout << "Score: " << score << "/100\n";
            }

        } while (guess != target);

        cout << "\nWould you like to play again? (y/n): ";
        cin >> replay;

    } while (replay == 'y' || replay == 'Y');

    cout << "\nThanks for playing! Goodbye.\n";

    return 0;
}