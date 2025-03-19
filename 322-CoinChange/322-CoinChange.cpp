class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Dynamic Programming
        // dp[value] = number of coins used. 
        vector<int> dp(amount + 1, amount + 1);
        dp[amount] = 0;
        for (int i = amount; i >= 0; i--) {
            // Can we make that amount with less coins?
            for (long long coin : coins) {
                if (i + coin >= amount + 1) {
                    continue;
                }
                dp[i] = min(dp[i + coin] + 1, dp[i]);
            }
        }

        return dp[0] == amount + 1 ? -1 : dp[0];
    }
};