bool isSafe(int* queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(queens[i] - col) == row - i)
            return false;
    }
    return true;
}

void addSolution(char**** res, int* returnSize, int* queens, int n) {
    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) {
            board[i][j] = (queens[i] == j) ? 'Q' : '.';
        }
        board[i][n] = '\0';
    }
    (*res)[*returnSize] = board;
    (*returnSize)++;
}

void solve(int row, int n, int* queens, char**** res, int* returnSize) {
    if (row == n) {
        addSolution(res, returnSize, queens, n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solve(row + 1, n, queens, res, returnSize);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int maxSolutions = 1000; 
    char*** res = (char***)malloc(sizeof(char**) * maxSolutions);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSolutions);
    int* queens = (int*)malloc(sizeof(int) * n); 

    solve(0, n, queens, &res, returnSize);

    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    free(queens);
    return res;
}
