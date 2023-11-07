#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2)
                cout << "|";
        }
        cout << "\n";
        if (i < 2)
            cout << "---+---+---\n";
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameover = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameover) {
        cout << "Current board:" << endl;
        printBoard(board);

        int input;
        cout << "Player " << currentPlayer << ", enter your move (cell number 1-9, or 0 to exit): ";

        while (!(cin >> input) || (input != 0 && (input < 1 || input > 9))) {
            cout << "Invalid input. Please enter a valid cell number (1-9) or 0 to exit: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (input == 0) {
            cout << "Exiting the game. Thanks for playing!\n";
            return 0;
        }

        int row = (input - 1) / 3;
        int col = (input - 1) % 3;

        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
        } else {
            cout << "Cell already occupied. Please enter a different cell number: ";
            continue;
        }

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            printBoard(board);  // Display the final board
            break;
        } else if (checkDraw(board)) {
            cout << "It's a draw!\n";
            printBoard(board);  // Display the final board
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
