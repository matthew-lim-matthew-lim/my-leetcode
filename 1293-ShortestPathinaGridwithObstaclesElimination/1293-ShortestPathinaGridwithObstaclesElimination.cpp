// Last updated: 7/21/2025, 9:09:42 PM
/* 
Use BFS.
Make it so that everytime you step onto an obstacle, you go up a level.
Make there be k levels, going from '0' to 'k - 1'. 

Since it's BFS, it will find the shortest path.

We can also use a int matrix for visited, where we allow visiting if we will visit at a lower level. 
 */
class Solution {
struct Step {
    int y;
    int x;
    int lvl;
    int stp;
};

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));

        queue<Step> q;
        q.push(Step(0, 0, 0, 0));

        while (!q.empty()) {
            Step curr = q.front();
            q.pop();

            int y = curr.y;
            int x = curr.x;
            int lvl = curr.lvl;
            int stp = curr.stp;

            if (y == n - 1 && x == m - 1) {
                return stp;
            }

            if (y + 1 < n) {
                int brick = grid[y + 1][x];
                if (lvl + brick < visited[y + 1][x] && lvl + brick <= k) {
                    q.push(Step(y + 1, x, lvl + brick, stp + 1));
                    visited[y + 1][x] = lvl + brick;
                }
            }
            if (y - 1 >= 0) {
                int brick = grid[y - 1][x];
                if (lvl + brick < visited[y - 1][x] && lvl + brick <= k) {
                    q.push(Step(y - 1, x, lvl + brick, stp + 1));
                    visited[y - 1][x] = lvl + brick;
                }
            }
            if (x + 1 < m) {
                int brick = grid[y][x + 1];
                if (lvl + brick < visited[y][x + 1] && lvl + brick <= k) {
                    q.push(Step(y, x + 1, lvl + brick, stp + 1));
                    visited[y][x + 1] = lvl + brick;
                }
            }
            if (x - 1 >= 0) {
                int brick = grid[y][x - 1];
                if (lvl + brick < visited[y][x - 1] && lvl + brick <= k) {
                    q.push(Step(y, x - 1, lvl + brick, stp + 1));
                    visited[y][x - 1] = lvl + brick;
                }
            }
        }

        return -1;
    }
};