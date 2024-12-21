class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // State machine DP.
        // States are buy (0), sell (1), cooldown (2).
        // dp[i][0] means the best profit if you bought at `i`.
        // dp[i][1] means the best profit if you sold at `i`.
        // dp[i][2] means the best profit if you cooldown at `i`.
        // buy -> sell -> cooldown 
        // dp[i][0] = max{k < i}(dp[k][2]); models cooldown -> buy.
        // dp[i][1] = max{k < i}(dp[k][0] + prices[i] - prices[k]); models buy -> sell.
        // dp[i][2] = max{k < i}(dp[k][1]); models sell -> cooldown.

        // Process in increasing order of `i`, and for each `i`, process in increasing order of `0` to `2`.
        // This is because we always need each of `0` to `2` for every level of `i`. 
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));

        for (int i = 1; i < prices.size(); i++) {
            // dp[i][0] = max{k < i}(dp[k][2]); models cooldown -> buy.
            for (int k = 0; k < i; k++) {
                dp[i][0] = max(dp[i][2], dp[k][2]);
            }
            // dp[i][1] = max{k < i}(dp[k][0] + prices[i] - prices[k]); models buy -> sell.
            for (int k = 0; k < i; k++) {
                dp[i][1] = max(dp[i][1], dp[k][0] + prices[i] - prices[k]);
            }
            // dp[i][2] = max{k < i}(dp[k][1]); models sell -> cooldown.
            for (int k = 0; k < i; k++) {
                dp[i][2] = max(dp[i][2], dp[k][1]);
            }
        }

        return max({dp[prices.size() - 1][0], dp[prices.size() - 1][1], dp[prices.size() - 1][2]});
    }
};