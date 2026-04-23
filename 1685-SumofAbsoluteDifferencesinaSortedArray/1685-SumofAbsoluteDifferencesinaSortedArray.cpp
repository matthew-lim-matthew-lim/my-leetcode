// Last updated: 4/24/2026, 12:00:16 AM
1/* 
2[2, 3, 5]
3
4LHS = curr * count - prefix
5RHS = suffix - curr * count
6 */
7class Solution {
8public:
9    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
10        int n = nums.size();
11
12        int prefix = 0;
13        int suffix = accumulate(nums.begin(), nums.end(), 0);
14
15        vector<int> res(n, 0);
16
17        for (int i = 0; i < n; i++) {
18            suffix -= nums[i];
19            res[i] += suffix - (nums[i] * (n-1-i));
20            res[i] += (nums[i] * i) - prefix;
21            prefix += nums[i];
22        }
23
24        return res;
25    }
26};