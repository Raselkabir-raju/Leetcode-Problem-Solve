bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1'; 
                int box_index = (i / 3) * 3 + (j / 3);

                if (rows[i][num] || cols[j][num] || boxes[box_index][num]) {
                    return false;
                }
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_index][num] = true;
            }
        }
    }
    return true;
}
