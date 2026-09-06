class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int islandCount = 0;

        for (int y = 0; y < row; y++) {
            for (int x = 0; x < col; x++) if (grid[y][x] == '1') {
                islandCount++;
                dfs(grid, x, y);
            }
        }

        return islandCount;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        int row = grid.size(), col = grid[0].size();
        if (x >= col || x < 0 || y >= row || y < 0 || grid[y][x] == '0') return;

        grid[y][x] = '0';
        dfs(grid, x, y-1);  //  up
        dfs(grid, x, y+1);  //  down
        dfs(grid, x-1, y);  //  left
        dfs(grid, x+1, y);  //  right
    }
};
