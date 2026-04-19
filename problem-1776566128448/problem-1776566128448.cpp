// Last updated: 4/19/2026, 12:35:28 PM
1/* 
2Use suffix
3*/
4class Solution {
5public:
6    int firstStableIndex(vector<int>& nums, int k) {
7        int n = nums.size();
8        vector<long long> suffix(n+1, INT_MAX);
9        for (int i = n-1; i >= 0; i--) {
10            suffix[i] = min(suffix[i+1], (long long)nums[i]);
11        }
12
13        long long currMax = INT_MIN;
14        for (int i = 0; i < n; i++) {
15            currMax = max(currMax, (long long)nums[i]);
16
17            // cout << currMax << " " << suffix[i] << endl;
18
19            if (currMax - suffix[i] <= k) {
20                return i;
21            }
22        }
23
24        return -1;
25    }
26};