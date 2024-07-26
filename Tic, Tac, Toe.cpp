#include <iostream>

using namespace std;

const char PLAYER_ONE = 'X';
const char PLAYER_TWO = 'O';
const char EMPTY = ' ';

char board[3][3] = {{EMPTY, EMPTY, EMPTY},
                    {EMPTY, EMPTY, EMPTY},
                    {EMPTY, EMPTY, EMPTY}};

void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void playerMove(char player) {
    int row, col;
    do {
        cout << "Player " << player << ", enter row (0-2): ";
        cin >> row;
        cout << "Player " << player << ", enter column (0-2): ";
        cin >> col;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY);

    board[row][col] = player;
}

int main() {
    char currentPlayer = PLAYER_ONE;

    while (true) {
        displayBoard();

        playerMove(currentPlayer);

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
    }

    return 0;
}
