// Last updated: 9/15/2025, 9:34:29 PM
/* 
Calculate the size of each island using union find. 
Then, go throughout the grid and for each '0', check the up, down, left, and right, summing 
each pair that is not belonging to the same island.
*/
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> gridGroups(n, vector<int>(m, -1));
        vector<int> groupSize;

        int res = 0;

        int currGroup = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && gridGroups[i][j] == -1) {
                    groupSize.push_back(0);
                    gridGroups[i][j] = currGroup;
                    vector<int> curr;
                    queue<vector<int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        curr = q.front();
                        q.pop();

                        groupSize[currGroup]++;
                        // cout << curr[0] << " " << curr[1] << " " << groupSize[currGroup] << endl;
                        res = max(res, groupSize[currGroup]);

                        if (curr[0] - 1 >= 0 && 
                            grid[curr[0] - 1][curr[1]] != 0 && 
                            gridGroups[curr[0] - 1][curr[1]] != currGroup
                        ) {
                            q.push({curr[0] - 1, curr[1]});
                            gridGroups[curr[0] - 1][curr[1]] = currGroup;
                        }
                        if (curr[0] + 1 < n && 
                            grid[curr[0] + 1][curr[1]] != 0 && 
                            gridGroups[curr[0] + 1][curr[1]] != currGroup
                        ) {
                            q.push({curr[0] + 1, curr[1]});
                            gridGroups[curr[0] + 1][curr[1]] = currGroup;
                        }
                        if (curr[1] - 1 >= 0 && 
                            grid[curr[0]][curr[1] - 1] != 0 && 
                            gridGroups[curr[0]][curr[1] - 1] != currGroup
                        ) {
                            q.push({curr[0], curr[1] - 1});
                            gridGroups[curr[0]][curr[1] - 1] = currGroup;
                        }
                        if (curr[1] + 1 < m && 
                            grid[curr[0]][curr[1] + 1] != 0 && 
                            gridGroups[curr[0]][curr[1] + 1] != currGroup
                        ) {
                            q.push({curr[0], curr[1] + 1});
                            gridGroups[curr[0]][curr[1] + 1] = currGroup;
                        }
                    }

                    currGroup++;
                }
            }
        }

        // cout << " pppp " << endl;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << gridGroups[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << " pppp " << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << " yo " << endl;
                unordered_set<int> groupSet;
                if (i - 1 >= 0 && gridGroups[i - 1][j] != -1) {
                    groupSet.insert(gridGroups[i - 1][j]);
                    // cout << i - 1 << " " << j << " " << gridGroups[i - 1][j] << endl;
                }
                if (i + 1 < n && gridGroups[i + 1][j] != -1) {
                    groupSet.insert(gridGroups[i + 1][j]);
                    // cout << i + 1 << " " << j << " " << gridGroups[i + 1][j] << endl;
                }
                if (j - 1 >= 0 && gridGroups[i][j - 1] != -1) {
                    groupSet.insert(gridGroups[i][j - 1]);
                    // cout << i << " " << j - 1 << " " << gridGroups[i][j - 1] << endl;
                }
                if (j + 1 < m && gridGroups[i][j + 1] != -1) {
                    groupSet.insert(gridGroups[i][j + 1]);
                    // cout << i << " " << j + 1 << " " << gridGroups[i][j + 1] << endl;
                }

                int currSize = 0;
                for (int group : groupSet) {
                    currSize += groupSize[group];
                }
                if (grid[i][j] == 0) {
                    currSize++;
                }
                res = max(res, currSize);
            }
        }

        return res;
    }
};