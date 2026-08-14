#include <iostream>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        initializeBoard();
        currentPlayer = 'X';
    }

    void initializeBoard() {
        char position = '1';

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                board[row][col] = position++;
            }
        }
    }

    void displayBoard() const {
        cout << "\n";
        cout << "=====================\n";
        cout << "     TIC-TAC-TOE\n";
        cout << "=====================\n";

        for (int row = 0; row < 3; row++) {
            cout << "     |     |     \n";
            cout << "  " << board[row][0]
                 << "  |  " << board[row][1]
                 << "  |  " << board[row][2] << "\n";

            if (row < 2) {
                cout << "-----|-----|-----\n";
            }
        }

        cout << "     |     |     \n";
        cout << "=====================\n";
    }

    bool makeMove(int position) {
        if (position < 1 || position > 9) {
            cout << "Invalid position. Choose 1-9.\n";
            return false;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That position is already occupied.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() const {
        // Check rows
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == currentPlayer &&
                board[row][1] == currentPlayer &&
                board[row][2] == currentPlayer) {
                return true;
            }
        }

        // Check columns
        for (int col = 0; col < 3; col++) {
            if (board[0][col] == currentPlayer &&
                board[1][col] == currentPlayer &&
                board[2][col] == currentPlayer) {
                return true;
            }
        }

        // Check main diagonal
        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer) {
            return true;
        }

        // Check opposite diagonal
        if (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer) {
            return true;
        }

        return false;
    }

    bool isDraw() const {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] != 'X' &&
                    board[row][col] != 'O') {
                    return false;
                }
            }
        }

        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int position;

        while (true) {
            displayBoard();

            cout << "Player " << currentPlayer << "'s turn.\n";
            cout << "Enter position (1-9): ";
            cin >> position;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (!makeMove(position)) {
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Congratulations! Player "
                     << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player X goes first.\n";

    game.play();

    cout << "Thanks for playing!\n";

    return 0;
}