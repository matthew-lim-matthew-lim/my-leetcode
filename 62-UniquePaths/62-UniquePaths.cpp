// Last updated: 4/9/2025, 1:52:18 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] represents the number of ways to get to (i, j). 
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n][m];
    }
};