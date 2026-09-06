class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int maxArea = 0;

        for (int y = 0; y < row; y++) {
            for (int x = 0; x < col; x++) if (grid[y][x] == 1) {
                maxArea = max(maxArea, dfs(grid, x, y));
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        int row = grid.size(), col = grid[0].size();
        if (x >= col || x < 0 || y >= row || y < 0 || grid[y][x] == 0) return 0;

        grid[y][x] = 0;
        return 1 + dfs(grid, x, y-1) + dfs(grid, x, y+1) +  dfs(grid, x-1, y) + dfs(grid, x+1, y);
    }
};
