class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check for row
        for (int y = 0; y < 9; y++) {
            unordered_map<char, int> colCheck;
            for (int x = 0; x < 9; x++) if (board[y][x] != '.'){
                char c = board[y][x];
                colCheck[c]++;
                if (colCheck[c] > 1) return false;
            }
        }

        //check for col
        for (int x = 0; x < 9; x++) {
            unordered_map<char, int> rowCheck;
            for (int y = 0; y < 9; y++) if (board[y][x] != '.'){
                char c = board[y][x];
                rowCheck[c]++;
                if (rowCheck[c] > 1) return false;
            }
        }

        //check for box
        int row = 0, col = 0;
        while (row < 9) {
            unordered_map<char, int> boxCheck;
            for (int y = row; y < row+3; y++) {
                for (int x = col; x < col+3; x++) if (board[y][x] != '.') {
                    char c = board[y][x];
                    boxCheck[c]++;
                    if (boxCheck[c] > 1) return false;
                }
            }

            col += 3;
            if (col >= 9) {
                col = 0;
                row += 3;
            }
        }
        
        return true;
    }
};
