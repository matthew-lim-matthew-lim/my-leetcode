// Last updated: 3/29/2026, 4:59:59 PM
1/* 
2Sliding window size k. 
3
4k = 4
5[1, 1, 1, 1, 1]
6   [0, 0, 1, 1]
7
8Use the window:
9curr += nums[i];
10curr -= nums[i-k/2];
11curr += nums[i-k] * strategy[i-k];
12*/
13class Solution {
14public:
15    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
16        long long curr = 0;
17        int n = prices.size();
18
19        for (int i = 0; i < n; i++) {
20            curr += prices[i] * strategy[i];
21        }
22        long long res = curr;
23
24        for (int i = 0; i < k / 2; i++) {
25            if (strategy[i] == 1) {
26                curr -= prices[i];
27            } else if (strategy[i] == -1) {
28                curr += prices[i];
29            }
30        }
31        for (int i = k / 2; i < k; i++) {
32            if (strategy[i] == 0) {
33                curr += prices[i];
34            } else if (strategy[i] == -1) {
35                curr += prices[i] * 2;
36            }
37        }
38        res = max(res, curr);
39
40        for (int i = k; i < n; i++) {
41            if (strategy[i] == 0) {
42                curr += prices[i];
43            } else if (strategy[i] == -1) {
44                curr += prices[i] * 2;
45            }
46            curr -= prices[i - k/2];
47            curr += prices[i-k] * strategy[i-k];
48            res = max(res, curr);
49        }
50
51        return res;
52    }
53};