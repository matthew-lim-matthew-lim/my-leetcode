class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            // Each letter in text1
            for (int j = 1; j <= m; j++) {
                // Each letter in text2
                if (text1[i - 1] == text2[j - 1]) {
                    // add a new letter to the LCS at dp[i][j].
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     // Each letter in text1
        //     for (int j = 1; j <= m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[n][m];
    }
};