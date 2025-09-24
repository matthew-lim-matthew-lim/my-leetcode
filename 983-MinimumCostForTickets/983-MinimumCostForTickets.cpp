// Last updated: 9/24/2025, 8:20:37 PM
/* 
Dynamic programming
dp[i] is the minimum cost to cover up to the day of index 'i'.

There are only 365 days. 
It is possible to, for each number, go back in days and account for that cost.
 */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j >= 0 && days[j] > days[i] - 1) {
                j--;
            }
            if (j < 0) {
                dp[i] = min(dp[i], costs[0]);
            } else {
                dp[i] = min(dp[i], costs[0] + dp[j]);
            }

            j = i;
            while (j >= 0 && days[j] > days[i] - 7) {
                j--;
            }
            if (j < 0) {
                dp[i] = min(dp[i], costs[1]);
            } else {
                dp[i] = min(dp[i], costs[1] + dp[j]);
            }

            j = i;
            while (j >= 0 && days[j] > days[i] - 30) {
                j--;
            }
            if (j < 0) {
                dp[i] = min(dp[i], costs[2]);
            } else {
                dp[i] = min(dp[i], costs[2] + dp[j]);
            }
        }

        return dp[n - 1];
    }
};