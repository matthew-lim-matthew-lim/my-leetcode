// Last updated: 4/5/2025, 3:47:30 PM
class Solution {
public:
    int climbStairs(int n) {
        // Bottom-up DP.
        vector<int> dp(n + 1, 0);
        // At dp[0], we are at step 0. There is 1 way to get to dp[0]. 
        dp[0] = 1;
        for (int i = 0; i < n + 1; i++) {
            if (i + 2 < n + 1) {
                dp[i + 2] += dp[i];
            }
            if (i + 1 < n + 1) {
                dp[i + 1] += dp[i];
            }
        }

        return dp[n];
    }
};