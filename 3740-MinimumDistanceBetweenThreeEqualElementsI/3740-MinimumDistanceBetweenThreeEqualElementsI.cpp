// Last updated: 4/10/2026, 11:50:48 AM
1/* 
2Easy with 3 for loops. O(n^3).
3
4Possible with binary search O(n log n).
5- (log n) different possible lengths.
6- (n) time for each check, using a sliding window.
7 */
8class Solution {
9public:
10    int minimumDistance(vector<int>& nums) {
11        int n = nums.size();
12        int res = INT_MAX;
13        for (int i = 0; i < n; i++) {
14            for (int j = i+1; j < n; j++) {
15                for (int k = j+1; k < n; k++) {
16                    if (
17                        nums[i] == nums[j] &&
18                        nums[i] == nums[k] && 
19                        res > abs(i - j) + abs(j - k) + abs(k - i)
20                    ) {
21                        res = abs(i - j) + abs(j - k) + abs(k - i);
22                    }
23                }
24            }
25        }
26
27        return res == INT_MAX ? -1 : res;
28    }
29};