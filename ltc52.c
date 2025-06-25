bool isSafe(int* queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(queens[i] - col) == row - i) {
            return false;
        }
    }
    return true;
}

void solve(int row, int n, int* queens, int* count) {
    if (row == n) {
        (*count)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solve(row + 1, n, queens, count);
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    int* queens = (int*)malloc(sizeof(int) * n);
    solve(0, n, queens, &count);
    free(queens);
    return count;
}
