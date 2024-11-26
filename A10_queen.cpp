#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int row, int N) {
    if (row >= N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            if (solveNQUtil(board, row + 1, N)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void printSolution(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter the size of the chess board (N): ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQUtil(board, 0, N)) {
        printSolution(board, N);
    } else {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}
