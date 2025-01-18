class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // Use Dijkstra with 0-1 edge weights. 
        // The edge weight to go to where the arrow is pointing is 0. 
        // The edge weight to go to the other 3 directions is 1. 
        // Implement it as a priority queue, with the cost for each move sorted in increasing order. 

        // Keep track of distance (cost) to each square in the grid
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dist[0][0] = 0;

        // Priority queue with increasing cost.
        // Consider it { y, x, cost }.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int y = curr[0];
            int x = curr[1];
            int cost = curr[2];

            // If in the bottom-right, return the cost (since this entry is the lowest in the pq).
            if (y == grid.size() - 1 && x == grid[0].size() - 1) {
                return cost;
            }

            // Consider all 4 directions of travel
            int alt_distance;
            if (y - 1 >= 0) {
                alt_distance = dist[y][x] + (grid[y][x] != 4);
                if (alt_distance < dist[y - 1][x]) {
                    dist[y - 1][x] = alt_distance;
                    pq.push({ y - 1, x, alt_distance });
                }
            } 
            if (y + 1 < grid.size()) {
                alt_distance = dist[y][x] + (grid[y][x] != 3);
                if (alt_distance < dist[y + 1][x]) {
                    dist[y + 1][x] = alt_distance;
                    pq.push({ y + 1, x, alt_distance });
                }
            } 
            if (x - 1 >= 0) {
                alt_distance = dist[y][x] + (grid[y][x] != 2);
                if (alt_distance < dist[y][x - 1]) {
                    dist[y][x - 1] = alt_distance;
                    pq.push({ y, x - 1, alt_distance });
                }
            } 
            if (x + 1 < grid[0].size()) {
                alt_distance = dist[y][x] + (grid[y][x] != 1);
                if (alt_distance < dist[y][x + 1]) {
                    dist[y][x + 1] = alt_distance;
                    pq.push({ y, x + 1, alt_distance });
                }
            }
        }

        return dist[grid.size() - 1][grid[0].size() - 1];
    }
};