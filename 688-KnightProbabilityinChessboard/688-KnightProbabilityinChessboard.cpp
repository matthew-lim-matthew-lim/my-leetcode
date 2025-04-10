// Last updated: 4/10/2025, 10:35:32 PM
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // This question crazy asf tho
        // Odds of each move is 1/8. 
        // If the knight moves off the board at any point, that counts as it having moved entirely off the board.

        // Each move odds are dp[k + 1][i + 1][j + 2] = dp[k][i][j] * 1/8;
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
        dp[0][row][column] = 1.0;

        vector<vector<int>> directions{ { 1, 2 }, { 2, 1 }, { -1, 2 }, { -2, 1 }, { 1, -2 }, { 2, -1 }, { -1, -2 }, { -2, -1 } };

        for (int layer = 0; layer < k; layer++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[layer][i][j] != 0) {
                        for (int d = 0; d < 8; d++) {
                            int y = i + directions[d][0];
                            int x = j + directions[d][1];
                            if (x < 0 || x >= n || y < 0 || y >= n) {
                                continue;
                            }
                            dp[layer + 1][y][x] += dp[layer][i][j] * 1/8;
                        }
                    }
                }
            }
        }

        // Now, sum the results in the last layer.
        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += dp[k][i][j];
            }
        }

        return res;
    }
};