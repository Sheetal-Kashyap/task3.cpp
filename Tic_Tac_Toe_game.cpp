#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

void printBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool isWinner(char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(char player) {
    int choice;
    cout << "Player " << player << ", enter a number (1-9): ";
    cin >> choice;

    // Validate choice
    if (choice < 1 || choice > 9) {
        cout << "Invalid move. Try again.\n";
        makeMove(player);
        return;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        cout << "This position is already taken. Try again.\n";
        makeMove(player);
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameWon = false;

    cout << "Tic-Tac-Toe Game\n";
    printBoard();

    while (!gameWon && !isBoardFull()) {
        makeMove(currentPlayer);
        printBoard();
        gameWon = isWinner(currentPlayer);
        if (!gameWon) {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!\n";
    } else {
        cout << "The game is a draw.\n";
    }

    return 0;
}
