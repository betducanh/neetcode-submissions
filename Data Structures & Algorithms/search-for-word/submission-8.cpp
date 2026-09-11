class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool valid = false;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == word[0]) valid += dfs(board, r, c, word);
                if (valid) return true;
            }
        }
        return valid;
    }

    bool dfs(vector<vector<char>> board, int r, int c, string word)    {
        if (!word.size())return true;
        if (board[r][c] != word[0]) return false;
        if (word.size()-1 == 0) return true;

        string rest = word.substr(1, word.size()-1);
        bool left = false;
        bool right = false;
        bool up = false;
        bool down = false;
        board[r][c] = '\0';
        if (r-1 >= 0)               up = dfs(board, r-1, c, rest);           
        if (r+1 < board.size())     down = dfs(board, r+1, c, rest);
        if (c-1 >= 0)               left = dfs(board, r, c-1, rest);
        if (c+1 < board[0].size())  right = dfs(board, r, c+1, rest);
        return left + right + up + down;
    }
};
