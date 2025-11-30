// Last updated: 11/30/2025, 7:52:31 PM
1/* 
2Dynamic programming with state machine?
3
4dp[index][state=buy/sell/cooldown/hold]
5
6buy <- cooldown
7sell <- buy/hold
8cooldown <- sell/cooldown
9hold <- buy/hold
10
11At each one, do the max of the possible previous states
12 */
13
14class Solution {
15public:
16    int maxProfit(vector<int>& prices) {
17        int n = prices.size();
18
19        vector<vector<int>> dp(n, vector<int>(4, 0));
20
21        dp[0][0] = -prices[0];
22        dp[0][1] = 0;
23        dp[0][2] = 0;
24        dp[0][3] = -prices[0];
25
26        for (int i = 1; i < n; i++) {
27            dp[i][0] = dp[i - 1][2] - prices[i];
28            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][3] + prices[i]);
29            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
30            dp[i][3] = max(dp[i - 1][0], dp[i - 1][3]);
31        }
32
33        return max({ dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
34    }
35};