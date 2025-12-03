// Last updated: 12/3/2025, 10:59:13 PM
1/*  
2Count downwards, and then exclude all elements that match the excluded element. 
3*/
4class Solution {
5public:
6    int countElements(vector<int>& nums, int k) {
7        sort(nums.begin(), nums.end());
8        int n = nums.size();
9        if (k == 0) {
10            return n;
11        }
12
13        if (k >= n) {
14            return 0;
15        }
16
17        int cutoffval = nums[n - k];
18        int i = n - k - 1;
19        while (i >= 0 && nums[i] == cutoffval) {
20            i--;
21        }
22
23        return i + 1;
24    }
25};