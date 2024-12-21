class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j == 1) {
                    // Buy state: Carry out a buy 
                    dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] - prices[i]);
                } else {
                    // Sell state: Carry out a sell
                    dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + prices[i] - fee);
                }
            }
        } 
        
        return dp[0][1];
    }
};