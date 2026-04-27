// Last updated: 4/28/2026, 12:56:15 AM
1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int sum = accumulate(nums.begin(), nums.end(), 0);
5
6        int lSum = 0;
7        int n = nums.size();
8        for (int i = 0; i < n; i++) {
9            if (i-1 >= 0) {
10                lSum += nums[i-1];
11            }
12            sum -= nums[i];
13            if (lSum == sum) {
14                return i;
15            }
16        }
17
18        return -1;
19    }
20};