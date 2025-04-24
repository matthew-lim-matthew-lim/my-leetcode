// Last updated: 4/25/2025, 12:24:43 AM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS tyshi
        // Keep track of layer tyshi

        // { y, x, layer }
        queue<vector<int>> q;

        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({ i, j, 0 });
                }
            }
        }

        int lastLayer = 0;
        while (!q.empty()) {
            int y = q.front()[0];
            int x = q.front()[1];
            int layer = q.front()[2];
            q.pop();

            lastLayer = layer;

            // Check up, down, left, right
            if (y + 1 < n && grid[y + 1][x] == 1) {
                grid[y + 1][x] = 2;
                q.push({ y + 1, x, layer + 1 });
            }
            if (y - 1 >= 0 && grid[y - 1][x] == 1) {
                grid[y - 1][x] = 2;
                q.push({ y - 1, x, layer + 1 });
            }
            if (x + 1 < m && grid[y][x + 1] == 1) {
                grid[y][x + 1] = 2;
                q.push({ y, x + 1, layer + 1 });
            }
            if (x - 1 >= 0 && grid[y][x - 1] == 1) {
                grid[y][x - 1] = 2;
                q.push({ y, x - 1, layer + 1 });
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return lastLayer;
    }
};