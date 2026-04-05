// Last updated: 4/5/2026, 4:39:20 PM
1/* 
2Dynamic programming.
3
4dp[i] is the max amount of money if i rob up to house `i`. 
5
6dp[i] = max(
7    nums[i] + dp[i-2],
8    dp[i-1]
9);
10
11Base cases
12Tricky because dp[0] means I cant rob dp[n-1].
13dp[1] means I can rob dp[n-1].
14
15Case 1: rob nums[0].
16compute dp from 0 to n-2.
17
18Case 2: rob nums[1].
19compute dp from 1 to n-1.
20 */
21class Solution {
22public:
23    int rob(vector<int>& nums) {
24        int n = nums.size();
25
26        if (n == 1) {
27            return nums[0];
28        }
29        if (n == 2) {
30            return max(nums[1], nums[0]);
31        }
32
33        int res = 0;
34
35        // Rob nums[0]
36        vector<int> dp1(n, 0);
37        dp1[0] = nums[0];
38        dp1[1] = dp1[0];
39        res = max(res, dp1[1]);
40        for (int i = 2; i <= n-2; i++) {
41            dp1[i] = max(
42                dp1[i-1],
43                dp1[i-2] + nums[i]
44            );
45
46            res = max(res, dp1[i]);
47        }
48
49        // Do not rob nums[0]
50        vector<int> dp2(n, 0);
51        dp2[1] = nums[1];
52        res = max(res, dp2[1]);
53        for (int i = 2; i <= n-1; i++) {
54            dp2[i] = max(
55                dp2[i-1],
56                dp2[i-2] + nums[i]
57            );
58
59            res = max(res, dp2[i]);
60        }
61
62        return res;
63    }
64};