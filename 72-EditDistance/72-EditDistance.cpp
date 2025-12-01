// Last updated: 12/1/2025, 8:06:04 PM
1/* 
2- For each letter in word1, you can insert/delete/replace. 
3
4- Consider if we changed that letter.
5- dp[i][j]
6
7- dp[i index word1][j index word2] = min number of edits to get here. 
8
9dp[0][0] = 1 -> Turn h into r
10dp[0][1] = 2 -> Turn h into r, add o
11dp[1][1] = 1 -> Turn h into r
12dp[1][2] = 2 -> Turn h into r, add s
13dp[2][2] = 2 -> Turn h into r, Turn r into s
14dp[3][2] =  -> Turn 
15
16dp[i][j]
17
18case 1: word[i] == word[j]
19dp[i][j] = dp[i-1][j-1];
20
21case 2: word[i] != word[j]
22dp[i][j] = 
23min(
24    dp[i-1][j-1] + 1,
25    dp[i-1][j] + 1,
26    dp[i][j-1] + 1
27)
28 */
29class Solution {
30public:
31    int minDistance(string word1, string word2) {
32        int n = word1.size();
33        int m = word2.size();
34
35        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
36        for (int i = 0; i < n + 1; i++) {
37            dp[i][0] = i;
38        } 
39        for (int j = 0; j < m + 1; j++) {
40            dp[0][j] = j;
41        }
42
43        for (int i = 1; i < n + 1; i++) {
44            for (int j = 1; j < m + 1; j++) {
45                if (word1[i-1] == word2[j-1]) {
46                    dp[i][j] = dp[i-1][j-1];
47                } else {
48                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
49                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
50                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
51                }
52            }
53        }
54
55        return dp[n][m];
56    }
57};