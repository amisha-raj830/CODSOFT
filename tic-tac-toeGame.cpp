#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3,vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() const {
        cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() const {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool checkDraw() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ')
                    return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int row, col;

    cout << "TIC-TAC-TOE GAME\n";
    game.displayBoard();

    do {
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row column): ";
        cin >> row >> col;

        if (game.makeMove(row - 1, col - 1)) {
            game.displayBoard();

            if (game.checkWin()) {
                cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                break;
            }

            if (game.checkDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            game.switchPlayer();
        } else {
            cout << "Invalid move. Try again.\n";
        }
    } while (true);
    return 0;
}