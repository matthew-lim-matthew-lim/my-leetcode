class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Build off solution for 200. Number of Islands
        // Keep track of all explored tiles.
        // For each unexplored water reached, perform a BFS, marking the visited tiles as explored.
        // During each BFS, keep track of the size of the island. Keep track of the largest
        // island over all of the BFS runs.

        int max_island_area = 0;
        vector<vector<bool>> explored(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && explored[i][j] == false) {
                    int curr_island_area = 0;
                    // bfs
                    stack<pair<int, int>> bfs_stack;
                    bfs_stack.push({i, j});

                    while (!bfs_stack.empty()) {
                        pair<int, int> curr_pos = bfs_stack.top();
                        bfs_stack.pop();
                        int y = curr_pos.first;
                        int x = curr_pos.second;
                        explored[y][x] = true;
                        curr_island_area++;
                        if (y + 1 < grid.size() && grid[y + 1][x] == 1 && explored[y + 1][x] == false) {
                            bfs_stack.push({y + 1, x});
                            explored[y + 1][x] = true;
                        }
                        if (y - 1 >= 0 && grid[y - 1][x] == 1 && explored[y - 1][x] == false) {
                            bfs_stack.push({y - 1, x});
                            explored[y - 1][x] = true;
                        }
                        if (x + 1 < grid[0].size() && grid[y][x + 1] == 1 && explored[y][x + 1] == false) {
                            bfs_stack.push({y, x + 1});
                            explored[y][x + 1] = true;
                        }
                        if (x - 1 >= 0 && grid[y][x - 1] == 1 && explored[y][x - 1] == false) {
                            bfs_stack.push({y, x - 1});
                            explored[y][x - 1] = true;
                        }
                    }

                    max_island_area = max(max_island_area, curr_island_area);
                }
            }
        }

        return max_island_area;
    }
};