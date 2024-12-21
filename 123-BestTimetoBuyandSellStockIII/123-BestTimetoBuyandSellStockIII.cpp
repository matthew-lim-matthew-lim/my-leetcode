class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>(2, 0)));
        // dp[index][0/1][buy/sell]
        // The last dimension is the current transaction number.
        // The state transition is now:
        // buy0 -> sell0 -> buy1 -> sell1
        // For the order of computation, we need to process level0 first, then level1.
        // This means that the previous level is ready to be proccessed each time. 
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int k = 1; k >= 0; k--) {
                for (int j = 0; j < 2; j++) {
                    if (j == 1) {
                        // Buy state: Carry out a buy 
                        dp[i][k][1] = max(dp[i + 1][k][1], dp[i + 1][k][0] - prices[i]);
                    } else {
                        // Sell state: Carry out a sell
                        dp[i][k][0] = max(dp[i + 1][k][0], dp[i + 1][k + 1][1] + prices[i]);
                    }
                }
            }
        } 
        
        // We return dp[0][1] (buy state) because the buy state accounts for the price we paid. 
        return max(dp[0][1][1], dp[0][0][1]);
    }
};