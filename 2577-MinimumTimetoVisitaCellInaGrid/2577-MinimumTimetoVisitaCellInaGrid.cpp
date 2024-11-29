class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // Djikstra

        // If adjacent paths from start are both >1 second, impossible.
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        // PQ for {time, row, col}.
        // Sorted by ascending minimum time. 
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; 
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            // If reach target
            if (curr[1] == grid.size() - 1 && curr[2] == grid[0].size() - 1) {
                return curr[0];
            }

            // Skip if already visited
            if (visited[curr[1]][curr[2]]) {
                continue;
            }
            visited[curr[1]][curr[2]] = true;

            if (curr[1] + 1 < grid.size() && !visited[curr[1] + 1][curr[2]]) {
                int wait_time = ((grid[curr[1] + 1][curr[2]] - curr[0]) % 2 == 0) ? 1 : 0;
                int next_time = max(grid[curr[1] + 1][curr[2]] + wait_time, curr[0] + 1);
                pq.push({next_time, curr[1] + 1, curr[2]});
            }
            if (curr[1] - 1 >= 0 && !visited[curr[1] - 1][curr[2]]) {
                int wait_time = ((grid[curr[1] - 1][curr[2]] - curr[0]) % 2 == 0) ? 1 : 0;
                int next_time = max(grid[curr[1] - 1][curr[2]] + wait_time, curr[0] + 1);
                pq.push({next_time, curr[1] - 1, curr[2]});
            }
            if (curr[2] + 1 < grid[0].size() && !visited[curr[1]][curr[2] + 1]) {
                int wait_time = ((grid[curr[1]][curr[2] + 1] - curr[0]) % 2 == 0) ? 1 : 0;
                int next_time = max(grid[curr[1]][curr[2] + 1] + wait_time, curr[0] + 1);
                pq.push({next_time, curr[1], curr[2] + 1});
            }
            if (curr[2] - 1 >= 0 && !visited[curr[1]][curr[2] - 1]) {
                int wait_time = ((grid[curr[1]][curr[2] - 1] - curr[0]) % 2 == 0) ? 1 : 0;
                int next_time = max(grid[curr[1]][curr[2] - 1] + wait_time, curr[0] + 1);
                pq.push({next_time, curr[1], curr[2] - 1});
            }
        }

        return -1;
    }
};