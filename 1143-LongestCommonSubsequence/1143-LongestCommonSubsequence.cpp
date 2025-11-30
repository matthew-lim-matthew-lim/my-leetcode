// Last updated: 11/30/2025, 11:40:20 PM
1/* 
2dp[i][j] = length
3dp[i index in text1][j index in text2] = length of combined subsequence
4
5- text1[i] == text2[j]: dp[i - 1][j - 1] + 1
6- text1[i] != text2[j]: max(dp[i - 1][j], dp[i][j - 1]);
7 */
8class Solution {
9public:
10    int longestCommonSubsequence(string text1, string text2) {
11        int n = text1.size() + 1;
12        int m = text2.size() + 1;
13
14        vector<vector<int>> dp(n, vector<int>(m, 0));
15
16        for (int i = 1; i < n; i++) {
17            for (int j = 1; j < m; j++) {
18                if (text1[i-1] == text2[j-1]) {
19                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
20                } else {
21                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
22                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
23                }
24            }
25        }
26
27        return dp[n-1][m-1];
28    }
29};