// Last updated: 5/5/2025, 1:21:20 PM
class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1'000'000'007;
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = 1;
        dp[1][0] = 2;
        dp[1][1] = 1;

        for (int i = 2; i < n; ++i) {
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + 2 * dp[i-1][1]) % MOD;
            dp[i][1] = (dp[i-2][0] + dp[i-1][1]) % MOD;
        }
        return dp[n-1][0];
    }
};
