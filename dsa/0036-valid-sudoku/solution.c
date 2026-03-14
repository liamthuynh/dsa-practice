bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    if (boardSize != 9){
        return false;
    }

    for (int r = 0; r < 9; r++){
        if (boardColSize[r] != 9){
            return false;
        }
    }

    int rows[9];
    int cols[9];
    int boxes[9];

    for (int i = 0; i < 9; i++) {
        rows[i] = 0;
    }
    for (int i = 0; i < 9; i++) {
        cols[i] = 0;
    }
    for (int i = 0; i < 9; i++) {
        boxes[i] = 0;
    }

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char ch = board[r][c];
            if (ch == '.') {
                continue;
            }

            int d = ch - '0';
            if (d < 1 || d > 9) {
                return false;
            }

            int mask = 1 << d;
            int boxIndex = (r / 3) * 3 + (c / 3);

            if ((rows[r] & mask) != 0) {
                return false;
            }
            if ((cols[c] & mask) != 0) {
                return false;
            }
            if ((boxes[boxIndex] & mask) != 0) {
                return false;
            }

            rows[r] = rows[r] | mask;
            cols[c] = cols[c] | mask;
            boxes[boxIndex] = boxes[boxIndex] | mask;
        }
    }

    return true;
}
