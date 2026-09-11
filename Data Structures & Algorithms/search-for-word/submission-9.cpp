class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (dfs(board, r, c, 0, word)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int r, int c, int i, string& word)    {
        if (i >= word.size()) return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || word[i] != board[r][c]) 
            return false;
        char temp = board[r][c];
        board[r][c] = '\0';
        i++;
        bool    found = dfs(board, r+1, c, i, word) ||
                        dfs(board, r, c+1, i, word) ||   
                        dfs(board, r-1, c, i, word) ||
                        dfs(board, r, c-1, i, word);
        board[r][c] = temp;
        return found;
    }
};
