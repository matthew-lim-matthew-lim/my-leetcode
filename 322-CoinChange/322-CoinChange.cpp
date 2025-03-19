class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Dynamic Programming
        // dp[value] = number of coins used. 

        // Bottom-up
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            // Can we make that amount with less coins?
            for (long long coin : coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};