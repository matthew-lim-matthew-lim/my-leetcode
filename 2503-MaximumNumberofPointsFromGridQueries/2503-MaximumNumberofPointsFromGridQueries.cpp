// Last updated: 3/28/2025, 4:42:51 PM
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // Basically, we BFS from top left, adding the cells if the value is small enough. 
        // Priority queue smallest to largest neighbours. 
        // We use a std::map<int, int> where { queryNumber, squareCount }
        // BFS, and keep track of the highest value seen. 
        // Every time we see a larger number, we need to track it. 
        map<int, int> queryToCount;
        queryToCount[0] = 0;
        // Smallest squares first;
        // { square val, y, x }
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ grid[0][0], 0, 0 });
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int largestSeen = grid[0][0];
        visited[0][0] = true;
        int currCount = 0;
        while (!pq.empty()) {
            currCount++;
            vector<int> curr = pq.top();
            pq.pop();

            int squareVal = curr[0];
            int y = curr[1];
            int x = curr[2];

            // cout << y << " " << x << endl;

            if (squareVal > largestSeen) {
                queryToCount[largestSeen + 1] = currCount - 1;
                largestSeen = squareVal;
            }

            // Check up, down, left, right
            if (y + 1 < n && visited[y + 1][x] == false) {
                pq.push({ grid[y + 1][x], y + 1, x });
                visited[y + 1][x] = true;
            }
            if (y - 1 >= 0 && visited[y - 1][x] == false) {
                pq.push({ grid[y - 1][x], y - 1, x });
                visited[y - 1][x] = true;
            }
            if (x + 1 < m && visited[y][x + 1] == false) {
                pq.push({ grid[y][x + 1], y, x + 1 });
                visited[y][x + 1] = true;
            }
            if (x - 1 >= 0 && visited[y][x - 1] == false) {
                pq.push({ grid[y][x - 1], y, x - 1 });
                visited[y][x - 1] = true;
            }
        }
        queryToCount[largestSeen + 1] = currCount;

        // For each query, find the smallest satisfactory one.
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto it = queryToCount.upper_bound(queries[i]);
            it--;
            res[i] = it->second;
        }

        return res;
    }
};