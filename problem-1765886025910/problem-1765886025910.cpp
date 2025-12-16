// Last updated: 12/16/2025, 10:53:45 PM
1class Solution {
2public:
3    int absDifference(vector<int>& nums, int k) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        
7        int lo = 0;
8        int hi = 0;
9        for (int i = 0; i < k; i++) {
10            lo += nums[i];
11            hi += nums[n - i - 1];
12        }
13
14        return abs(hi - lo);
15    }
16};