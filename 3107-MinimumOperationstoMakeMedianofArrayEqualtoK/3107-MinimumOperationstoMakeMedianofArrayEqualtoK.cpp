// Last updated: 3/29/2026, 2:33:54 PM
1/* 
2Odd length:
3If `k > median`, you need to add to median, and the following numbers that are valued below k.
4If `k < median`, you uneed to subtract from median, and the previous numbers that are valued above k.
5
6Even length...
7The larger of the 2 medians is taken. 
8*/
9class Solution {
10public:
11    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
12        sort(nums.begin(), nums.end());
13        int n = nums.size();
14        int curr_median = nums[n / 2];
15
16        long long res = 0;
17
18        if (curr_median < k) {
19            for (int i = n / 2; i < n; i++) {
20                if (nums[i] < k) {
21                    res += k - nums[i];
22                }
23            }
24        } else {
25            for (int i = n / 2; i >= 0; i--) {
26                if (nums[i] > k) {
27                    res += nums[i] - k;
28                }
29            }
30        }
31
32        return res;
33    }
34};