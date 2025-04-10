// Last updated: 4/10/2025, 4:58:09 PM
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // If last char equal, +1 to current longest.
        // If last char not equal, repeat for text1 with 1 less char and text2, as well as text1 and text2 with 1 less char.
        // if (text1.back() == text2.back()), 
        // dp[text1][text2] = dp[text1 - 1][text2 - 1] + 1;
        // else 
        // dp[text1][text2] = max(dp[text1 - 1][text2], dp[text1][text2 - 1]);
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int TL = (i - 1 >= 0 && j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                int TT = (i - 1 >= 0) ? dp[i - 1][j] : 0;
                int LL = (j - 1 >= 0) ? dp[i][j - 1] : 0;

                if (text1[i] == text2[j]) {
                    dp[i][j] = TL + 1;
                } else {
                    dp[i][j] = max(TT, LL);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};