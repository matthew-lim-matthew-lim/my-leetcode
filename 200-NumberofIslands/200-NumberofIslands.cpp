class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Keep track of all explored tiles.
        // For each unexplored water reached, perform a BFS, marking the visited tiles as explored.
        // For each BFS started, incrmeent a count of islands.

        int islands_count = 0;
        vector<vector<bool>> explored(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && explored[i][j] == false) {
                    islands_count++;
                    // bfs
                    stack<pair<int, int>> bfs_stack;
                    bfs_stack.push({i, j});

                    while (!bfs_stack.empty()) {
                        pair<int, int> curr_pos = bfs_stack.top();
                        bfs_stack.pop();
                        int y = curr_pos.first;
                        int x = curr_pos.second;
                        explored[y][x] = true;
                        if (y + 1 < grid.size() && grid[y + 1][x] == '1' && explored[y + 1][x] == false) {
                            bfs_stack.push({y + 1, x});
                        }
                        if (y - 1 >= 0 && grid[y - 1][x] == '1' && explored[y - 1][x] == false) {
                            bfs_stack.push({y - 1, x});
                        }
                        if (x + 1 < grid[0].size() && grid[y][x + 1] == '1' && explored[y][x + 1] == false) {
                            bfs_stack.push({y, x + 1});
                        }
                        if (x - 1 >= 0 && grid[y][x - 1] == '1' && explored[y][x - 1] == false) {
                            bfs_stack.push({y, x - 1});
                        }
                    }
                }
            }
        }

        return islands_count;
    }
};