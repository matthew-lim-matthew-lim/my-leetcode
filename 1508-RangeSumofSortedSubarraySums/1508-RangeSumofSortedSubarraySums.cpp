// Last updated: 4/17/2026, 12:17:25 AM
1class Solution {
2public:
3    int rangeSum(vector<int>& nums, int n, int left, int right) {
4        // prefix sums
5
6        vector<long long> pre(n + 1, 0);
7        for (int i = 1; i <= n; i++) {
8            pre[i] = pre[i - 1] + nums[i - 1];
9        }
10        vector<long long> res;
11        for (int i = 1; i <= n; i++) {
12            for (int j = i; j <= n; j++) {
13                res.push_back(pre[j] - pre[i - 1]);
14            }
15        }
16        sort(res.begin(), res.end());
17        long long sum = 0;
18        for (int i = left - 1; i < right; i++) {
19            sum = (sum + res[i]) % 1'000'000'007;
20        }
21        return sum;
22    }
23};