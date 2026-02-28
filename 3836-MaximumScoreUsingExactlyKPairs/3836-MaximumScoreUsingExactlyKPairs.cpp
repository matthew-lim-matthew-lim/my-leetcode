// Last updated: 3/1/2026, 1:06:58 AM
1/* 
2Dynamic programming?
3
4This is like the subsequence DP problem.
5It is possible to enforce the K levels by making a table with `k` base levels. 
6
7This is the `k` level.
8Index `i` of nums1.
9Index `j` of nums2.
10dp[k][i][j] = max(
11    dp[k-1][i-1][j-1] + nums[i] * nums[j],
12    dp[k][i-1][j],
13    dp[k][i][j-1]
14);
15 */
16class Solution {
17public:
18    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
19        int n = nums1.size();
20        int m = nums2.size();
21        vector<vector<vector<long long>>> 
22            dp(k+1, vector<vector<long long>>(n+1, vector<long long>(m+1, LLONG_MIN)));
23
24        for (int i = 1; i < n+1; i++) {
25            for (int j = 1; j < m+1; j++) {
26                // cout << (nums1[i-1] * nums2[j-1]) << endl;
27                dp[1][i][j] = max({
28                    (long long)(nums1[i-1]) * (long long)nums2[j-1],
29                    dp[1][i-1][j],
30                    dp[1][i][j-1]
31                });
32            }
33        }
34
35        for (int level = 2; level < k+1; level++) {
36            for (int i = 1; i < n+1; i++) {
37                for (int j = 1; j < m+1; j++) {
38                    // cout << (nums1[i-1] * nums2[j-1]) << endl;
39                    if (dp[level-1][i-1][j-1] == LLONG_MIN) {
40                        continue;
41                    }
42                    dp[level][i][j] = max({
43                        dp[level-1][i-1][j-1] + (long long)nums1[i-1] * (long long)nums2[j-1],
44                        dp[level][i-1][j],
45                        dp[level][i][j-1]
46                    });
47                }
48            }
49        }
50
51        // cout << "printing!: " << endl;
52        // for (int level = 1; level < k+1; level++) {
53        //     for (int i = 1; i < n+1; i++) {
54        //         for (int j = 1; j < m+1; j++) {
55        //             cout << dp[level][i][j] << " ";
56        //         }
57        //         cout << endl;
58        //     }
59        // }
60
61        return dp[k][n][m];
62    }
63};