// Last updated: 4/10/2025, 6:30:11 PM
class Solution {
public:
    int numSquares(int n) {
        // Consider the numbers we can make with perfect squares. 
        // Keep track of the numbers we can make with perfect squares, and go down the list to make the current number.
        // vector<int> perfSquares;
        // for (int i = 1; i < n; i++) {
        //     if (pow((int)sqrt(i), 2) == i) {
        //         perfSquares.push_back(i);
        //     }
        // }

        // We can find how many numbers it takes to make each number
        // dp[i] = min(dp[i], dp[i - j] + dp[j]);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            // cout << i << endl;
            if (pow((int)sqrt(i), 2) == i) {
                dp[i] = 1;
                continue;
            }
            dp[i] = INT_MAX;
            for (int j = 1; j < i; j++) {
                dp[i] = min(dp[i], dp[i - j] + dp[j]);
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << dp[i] << endl;
        // }

        return dp[n];
    }
};