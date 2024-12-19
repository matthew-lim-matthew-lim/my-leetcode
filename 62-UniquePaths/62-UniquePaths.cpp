class Solution {
public:
    int uniquePaths(int m, int n) {
        // At any point, the robot can move either down or right. 
        // opt(i, j) is the number of possible unique paths to get to point (i, j).
        // opt(i, j) = opt(i - 1, j) + opt(i, j - 1);
        // opt(0, 0) = 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int up = i - 1 >= 0 ? dp[i - 1][j] : 0;
                int left = j - 1 >= 0 ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        } 
        return dp[m - 1][n - 1];
    }
};