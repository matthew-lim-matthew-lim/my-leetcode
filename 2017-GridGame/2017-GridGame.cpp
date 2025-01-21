class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // Notice that the size is only 2*n.
        // Therefore, we can consider what the total is when we move down at `n` different spots.
        // Feels like prefix sum!


        // Build the prefix sums
        vector<long long> top(grid[0].size(), grid[0][grid[0].size() - 1]);
        vector<long long> bottom(grid[0].size(), grid[1][0]);
        for (int i = 1; i < grid[0].size(); i++) {
            // Top
            top[(grid[0].size() - 1) - i] = top[grid[0].size() - i] + grid[0][(grid[0].size() - 1) - i];
            // Bottom
            bottom[i] = bottom[i - 1] + grid[1][i];
        }

        // Find the minimum combination
        long long res = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); i++) {
            long long top_sum = i + 1 < grid[0].size() ? top[i + 1] : 0;
            long long bottom_sum = i - 1 >= 0 ? bottom[i - 1] : 0;
            res = min(res, max(top_sum, bottom_sum));
        }

        return res;
    }
};