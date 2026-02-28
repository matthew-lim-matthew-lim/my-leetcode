// Last updated: 3/1/2026, 1:28:11 AM
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
21
22        long long NEG_INF = -1e15;
23        vector<vector<vector<long long>>> 
24            dp(k+1, vector<vector<long long>>(n+1, vector<long long>(m+1, NEG_INF)));
25
26        for (int level = 1; level < k+1; level++) {
27            for (int i = 1; i < n+1; i++) {
28                for (int j = 1; j < m+1; j++) {
29                    // cout << (nums1[i-1] * nums2[j-1]) << endl;
30                    long long prod = (long long)nums1[i-1] * (long long)nums2[j-1];
31
32                    long long skipScore = max(dp[level][i-1][j], dp[level][i][j-1]);
33
34                    long long matchScore = NEG_INF;
35
36                    if (level == 1) {
37                        matchScore = prod;
38                    } else if (dp[level-1][i-1][j-1] > NEG_INF) {
39                        matchScore = dp[level-1][i-1][j-1] + prod;
40                    }
41
42                    dp[level][i][j] = max(skipScore, matchScore);
43                }
44            }
45        }
46
47        return dp[k][n][m];
48    }
49};