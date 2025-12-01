// Last updated: 12/1/2025, 11:53:20 PM
1/* 
2Ts hard bro
3
4- dp[i][j] where i + j = index in s3.
5
6s1[i] == s3[i+j]
7dp[i][j] = max(dp[i][j], dp[i-1][j]);
8
9s2[j] == s3[i+j]
10dp[i][j] = max(dp[i][j], dp[i][j-1]);
11 */
12class Solution {
13public:
14    bool isInterleave(string s1, string s2, string s3) {
15        int n = s1.size();
16        int m = s2.size();
17
18        if (n + m != s3.size()) {
19            return false;
20        }
21
22        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
23        dp[0][0] = 1;
24        for (int i = 1; i < n+1; i++) {
25            if (s1[i-1] == s3[i-1]) {
26                dp[i][0] = dp[i-1][0];
27            }
28        }
29        for (int j = 1; j < m+1; j++) {
30            if (s2[j-1] == s3[j-1]) {
31                dp[0][j] = dp[0][j-1];
32            }
33        }
34
35        for (int i = 1; i < n+1; i++) {
36            for (int j = 1; j < m+1; j++) {
37                if (s1[i-1] == s3[i+j-1]) {
38                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
39                }
40                if (s2[j-1] == s3[i+j-1]) {
41                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
42                }
43            }
44        }
45
46        // for (int i = 0; i < n+1; i++) {
47        //     for (int j = 0; j < m+1; j++) {
48        //         cout << dp[i][j] << " ";
49        //     }
50        //     cout << endl;
51        // }
52
53        return dp[n][m];
54    }
55};