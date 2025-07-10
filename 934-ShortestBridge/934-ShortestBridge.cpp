// Last updated: 7/10/2025, 3:23:30 PM
/* 
BFS from the borders of an island. 

Keep BFSing until the neighbour is part of the other island. 
*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> island(n, vector<int>(m, 0));
        queue<vector<int>> bridgeQ;

        int currIsland = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && island[i][j] == 0) {
                    // This is a new island, currIsland. 
                    queue<vector<int>> q;
                    q.push({ i, j });
                    island[i][j] = currIsland;

                    while (!q.empty()) {
                        int y = q.front()[0];
                        int x = q.front()[1];
                        q.pop();

                        if (currIsland == 1) {
                            bridgeQ.push({ y, x, 0 });
                        }

                        if (y + 1 < n && island[y + 1][x] == 0 && grid[y + 1][x] == 1) {
                            island[y + 1][x] = currIsland;
                            q.push({ y + 1, x });
                        }
                        if (y - 1 >= 0 && island[y - 1][x] == 0 && grid[y - 1][x] == 1) {
                            island[y - 1][x] = currIsland;
                            q.push({ y - 1, x });
                        }
                        if (x + 1 < m && island[y][x + 1] == 0 && grid[y][x + 1] == 1) {
                            island[y][x + 1] = currIsland;
                            q.push({ y, x + 1 });
                        }
                        if (x - 1 >= 0 && island[y][x - 1] == 0 && grid[y][x - 1] == 1) {
                            island[y][x - 1] = currIsland;
                            q.push({ y, x - 1 });
                        }
                    }

                    currIsland++;
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << island[i][j];
        //     }
        //     cout << endl;
        // }

        while (!bridgeQ.empty()) {
            int y = bridgeQ.front()[0];
            int x = bridgeQ.front()[1];
            int lvl = bridgeQ.front()[2];
            bridgeQ.pop();

            if (y + 1 < n && island[y + 1][x] != 1) {
                if (island[y + 1][x] == 2) {
                    return lvl;
                }
                island[y + 1][x] = 1;
                bridgeQ.push({ y + 1, x, lvl + 1 });
            }
            if (y - 1 >= 0 && island[y - 1][x] != 1) {
                if (island[y - 1][x] == 2) {
                    return lvl;
                }
                island[y - 1][x] = 1;
                bridgeQ.push({ y - 1, x, lvl + 1 });
            }
            if (x + 1 < m && island[y][x + 1] != 1) {
                if (island[y][x + 1] == 2) {
                    return lvl;
                }
                island[y][x + 1] = 1;
                bridgeQ.push({ y, x + 1, lvl + 1 });
            }
            if (x - 1 >= 0 && island[y][x - 1] != 1) {
                if (island[y][x - 1] == 2) {
                    return lvl;
                }
                island[y][x - 1] = 1;
                bridgeQ.push({ y, x - 1, lvl + 1 });
            }
        }

        return 0;
    }
};