class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // opt(i, j) is the minimum path sum to get to (i, j).
        // opt(i, j) = min(opt(i - 1, j), opt(i, j - 1)) + grid[i][j];
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int top = i - 1 >= 0 ? dp[i - 1][j] : INT_MAX;
                int left = j - 1 >= 0 ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = min(top, left) + grid[i][j];
            }
        }
        
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};