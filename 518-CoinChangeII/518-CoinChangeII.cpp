// Last updated: 4/11/2025, 1:10:44 PM
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Find the number of ways to make up any amount of coin.
        // For each 'val', add the number of ways to make up dp[val - coins[i]], for all i in coins.
        vector<vector<unsigned long long>> dp(coins.size(), vector<unsigned long long>(amount + 1, 0));

        // We are working with combinations, so order doesn't matter. 
        // Therefore, 2 + 2 + 1 is the same as 1 + 2 + 2
        // For each value, find what you can make using only the coins up to the jth coin. 
        // Each layer, you can only look at the previous layer. 
        // That way, there is an order to the coins that you use (always increasing). 
        
        for (int layer = 0; layer < coins.size(); layer++) {
            // Layer tells us which coin we are now considering.
            dp[layer][0] = 1;
            for (int val = 1; val < amount + 1; val++) {
                if (layer - 1 >= 0) {
                    dp[layer][val] += dp[layer - 1][val];
                } 
                if (val - coins[layer] >= 0) {
                    dp[layer][val] += dp[layer][val - coins[layer]];
                }
            }
        }

        return dp[coins.size() - 1][amount];
    }
};