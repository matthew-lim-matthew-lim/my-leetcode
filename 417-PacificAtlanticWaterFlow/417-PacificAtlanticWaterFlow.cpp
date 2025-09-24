// Last updated: 9/24/2025, 6:40:56 PM
/* 
Brute force BFS from the edge squares (BFS from multiple sources).
Each edge square can go to a square >= the current square.
 */
class Solution {
public:
    struct Reach {
        bool pacific = false;
        bool atlantic = false;
    };

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<Reach>> valid(n, vector<Reach>(m));

        // Mark all squares that can reach pacific first

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            valid[i][0].pacific = true;
            q.push({ i, 0 });
            visited[i][0] = true;
        }
        for (int i = 0; i < m; i++) {
            valid[0][i].pacific = true;
            q.push({ 0, i });
            visited[0][i] = true;
        }

        while (!q.empty()) {
            auto [ y, x ] = q.front();
            q.pop();

            valid[y][x].pacific = true;

            if (y + 1 < n && !visited[y + 1][x] && heights[y + 1][x] >= heights[y][x]) {
                q.push({ y + 1, x });
                visited[y + 1][x] = true;
            }
            if (y - 1 >= 0 && !visited[y - 1][x] && heights[y - 1][x] >= heights[y][x]) {
                q.push({ y - 1, x });
                visited[y - 1][x] = true;
            }
            if (x + 1 < m && !visited[y][x + 1] && heights[y][x + 1] >= heights[y][x]) {
                q.push({ y, x + 1 });
                visited[y][x + 1] = true;
            }
            if (x - 1 >= 0 && !visited[y][x - 1] && heights[y][x - 1] >= heights[y][x]) {
                q.push({ y, x - 1 });
                visited[y][x - 1] = true;
            }
        }

        // Now, mark all squares that can reach atlantic
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            valid[i][m - 1].atlantic = true;
            q.push({ i, m - 1 });
            visited[i][m - 1] = true;
        }
        for (int i = 0; i < m; i++) {
            valid[n - 1][i].atlantic = true;
            q.push({ n - 1, i });
            visited[n - 1][i] = true;
        }

        while (!q.empty()) {
            auto [ y, x ] = q.front();
            q.pop();

            valid[y][x].atlantic = true;

            if (y + 1 < n && !visited[y + 1][x] && heights[y + 1][x] >= heights[y][x]) {
                q.push({ y + 1, x });
                visited[y + 1][x] = true;
            }
            if (y - 1 >= 0 && !visited[y - 1][x] && heights[y - 1][x] >= heights[y][x]) {
                q.push({ y - 1, x });
                visited[y - 1][x] = true;
            }
            if (x + 1 < m && !visited[y][x + 1] && heights[y][x + 1] >= heights[y][x]) {
                q.push({ y, x + 1 });
                visited[y][x + 1] = true;
            }
            if (x - 1 >= 0 && !visited[y][x - 1] && heights[y][x - 1] >= heights[y][x]) {
                q.push({ y, x - 1 });
                visited[y][x - 1] = true;
            }
        }
        
        // Collect all the answers

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (valid[i][j].pacific && valid[i][j].atlantic) {
                    res.push_back({ i, j });
                }
            }
        }
        return res;
    }
};