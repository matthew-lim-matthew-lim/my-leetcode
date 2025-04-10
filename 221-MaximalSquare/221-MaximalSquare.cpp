// Last updated: 4/10/2025, 11:17:54 AM
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // DP
        // Go from top left to bottom right.
        // At each '1' square, this square is the min(TL, TT, LL) + 1
        int n = matrix.size();
        int m = matrix[0].size();
        // Use matrix as the dp table? - Can't since matrix is a matrix of chars.
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                }
            }
        }

        int maxSquare = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0) {
                    continue;
                }
                int TL = (i - 1 >= 0 && j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                int TT = (i - 1 >= 0) ? dp[i - 1][j] : 0;
                int LL = (j - 1 >= 0) ? dp[i][j - 1] : 0;

                dp[i][j] = min(TL, min(TT, LL)) + 1;
                maxSquare = max(maxSquare, dp[i][j]);
            }
        }

        return pow(maxSquare, 2);
    }
};