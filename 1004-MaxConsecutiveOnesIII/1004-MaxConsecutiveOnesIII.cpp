// Last updated: 4/26/2026, 5:46:21 PM
1/* 
2Sliding window. 
3 */
4class Solution {
5public:
6    int longestOnes(vector<int>& nums, int k) {
7        int n = nums.size();
8        int res = 0;
9
10        int l = 0;
11        for (int i = 0; i < n; i++) {
12            if (nums[i] == 0) {
13                k--;
14            }
15            while (k < 0) {
16                if (nums[l] == 0) {
17                    k++;
18                }
19                l++;
20            }
21            res = max(res, i - l + 1);
22        }
23
24        return res;
25    }
26};