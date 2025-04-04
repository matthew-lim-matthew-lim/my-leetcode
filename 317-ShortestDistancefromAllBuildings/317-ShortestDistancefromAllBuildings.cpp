// Last updated: 4/5/2025, 12:47:13 AM
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // BFS from every '1', adding the sums.

        queue<vector<int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int numHouses = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    numHouses++;
                }
            }
        }


        vector<vector<int>> housesAtPos(n, vector<int>(m, 0));
        vector<vector<int>> distToPos(n, vector<int>(m, 0));

        int shortestDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                visited[i][j] = true;
                q.push({ i, j, 0 });
                int currDist = 0;

                while (!q.empty()) {
                    vector<int> curr = q.front();
                    q.pop();
                    int y = curr[0];
                    int x = curr[1];
                    int d = curr[2];

                    // If it is a building, add it to the total for this node.

                    if (y + 1 < n && visited[y + 1][x] == false) {
                        if (grid[y + 1][x] == 0) {
                            q.push({ y + 1, x, d + 1 });
                            housesAtPos[y + 1][x]++;
                            distToPos[y + 1][x] += d + 1;
                        }
                        visited[y + 1][x] = true;
                    }
                    if (y - 1 >= 0 && visited[y - 1][x] == false) {
                        if (grid[y - 1][x] == 0) {
                            q.push({ y - 1, x, d + 1 });
                            housesAtPos[y - 1][x]++;
                            distToPos[y - 1][x] += d + 1;
                        }
                        visited[y - 1][x] = true;
                    }
                    if (x + 1 < m && visited[y][x + 1] == false) {
                        if (grid[y][x + 1] == 0) {
                            q.push({ y, x + 1, d + 1 });
                            housesAtPos[y][x + 1]++;
                            distToPos[y][x + 1] += d + 1;
                        }
                        visited[y][x + 1] = true;
                    }
                    if (x - 1 >= 0 && visited[y][x - 1] == false) {
                        if (grid[y][x - 1] == 0) {
                            q.push({ y, x - 1, d + 1 });
                            housesAtPos[y][x - 1]++;
                            distToPos[y][x - 1] += d + 1;
                        }
                        visited[y][x - 1] = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (housesAtPos[i][j] == numHouses) {
                    shortestDist = min(shortestDist, distToPos[i][j]);
                }
            }
        }

        return shortestDist == INT_MAX ? -1 : shortestDist;
    }
};