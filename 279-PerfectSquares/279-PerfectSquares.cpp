// Last updated: 4/10/2025, 6:30:28 PM
class Solution {
public:
    int numSquares(int n) {
        // We can find how many numbers it takes to make each number
        // dp[i] = min(dp[i], dp[i - j] + dp[j]);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (pow((int)sqrt(i), 2) == i) {
                dp[i] = 1;
                continue;
            }
            dp[i] = INT_MAX;
            for (int j = 1; j < i; j++) {
                dp[i] = min(dp[i], dp[i - j] + dp[j]);
            }
        }

        return dp[n];
    }
};