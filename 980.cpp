class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero = 0, a = 0, b = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) zero++;
                else if (grid[r][c] == 1) {
                    a = r;
                    b = c;
                }
            }
        }
        return path(grid, a, b, zero);
    }

private:
    int path(vector<vector<int>>& grid, int x, int y, int zero) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1) return 0;
        if (grid[x][y] == 2) return zero == -1 ? 1 : 0;
        grid[x][y] = -1;
        zero--;
        int totalCount = path(grid, x + 1, y, zero) + path(grid, x, y + 1, zero) +
                         path(grid, x - 1, y, zero) + path(grid, x, y - 1, zero);
        grid[x][y] = 0;
        zero++;
        return totalCount;
    }
};
