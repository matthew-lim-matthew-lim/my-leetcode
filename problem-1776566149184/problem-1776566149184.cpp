// Last updated: 4/19/2026, 12:35:49 PM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<long long> suffix(n+1, INT_MAX);
6        for (int i = n-1; i >= 0; i--) {
7            suffix[i] = min(suffix[i+1], (long long)nums[i]);
8        }
9
10        long long currMax = INT_MIN;
11        for (int i = 0; i < n; i++) {
12            currMax = max(currMax, (long long)nums[i]);
13
14            // cout << currMax << " " << suffix[i] << endl;
15
16            if (currMax - suffix[i] <= k) {
17                return i;
18            }
19        }
20
21        return -1;
22    }
23};