class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        // BFS? 
        // There are many ways to do this problem.
        // After you catch all the fish at a cell, does it become a land cell?
        // As per discussion: It does not.

        // Simply start BFS from every non-explored tile.
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || grid[i][j] == 0) continue;
                
                // BFS from this tile.
                int currFish = 0;
                stack<pair<int, int>> stk;
                stk.push({ i, j });
                visited[i][j] = true;
                while (!stk.empty()) {
                    pair<int, int> curr = stk.top();
                    stk.pop();
                    int y = curr.first;
                    int x = curr.second;
                    currFish += grid[y][x];
                    res = max(res, currFish);

                    if (y + 1 < n && visited[y + 1][x] == false && grid[y + 1][x] != 0) {
                        visited[y + 1][x] = true;
                        stk.push({ y + 1, x });
                    }
                    if (y - 1 >= 0 && visited[y - 1][x] == false && grid[y - 1][x] != 0) {
                        visited[y - 1][x] = true;
                        stk.push({ y - 1, x });
                    }
                    if (x + 1 < m && visited[y][x + 1] == false && grid[y][x + 1] != 0) {
                        visited[y][x + 1] = true;
                        stk.push({ y, x + 1 });
                    }
                    if (x - 1 >= 0 && visited[y][x - 1] == false && grid[y][x - 1] != 0) {
                        visited[y][x - 1] = true;
                        stk.push({ y, x - 1 });
                    }
                }
            }
        }

        return res;
    }
};