class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Solve opt(i) which is the min cost to climb to 'i'.
        // opt(i) = min(opt(i - 1) + opt[i - 1], opt(i - 2) + opt[i - 2]);

        vector<int> dp(cost.size() + 1, INT_MAX);

        // Solve in bottom-up order.
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < cost.size() + 1; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};