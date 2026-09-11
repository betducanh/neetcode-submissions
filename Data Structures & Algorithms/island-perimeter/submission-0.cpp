class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> checked;
        for (int r = 0; r < grid.size(); r++) {
            checked.push_back({});
            for (int c = 0; c < grid[0].size(); c++)  {
                checked[r].push_back(false);
            }
        }

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) return dfs(grid, checked, r, c);
            }
        }
        return 0;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& checked, int r, int c) {
        if (r < 0 || c < 0 ||
            r >= grid.size() || c >= grid[0].size() ||
            !grid[r][c] || checked[r][c] == true) 
            return 0;

        int total = 0;
        checked[r][c] = true;

        if (r-1 < 0 || !grid[r-1][c]) total++;
        if (c-1 < 0 || !grid[r][c-1]) total++;
        if (r+1 >= grid.size() || !grid[r+1][c]) total++;
        if (c+1 >= grid[0].size() || !grid[r][c+1]) total++;
        total += dfs(grid, checked, r-1, c)
            + dfs(grid, checked, r, c-1)
            + dfs(grid, checked, r+1, c)
            + dfs(grid, checked, r, c+1);
        return total;
    }
};