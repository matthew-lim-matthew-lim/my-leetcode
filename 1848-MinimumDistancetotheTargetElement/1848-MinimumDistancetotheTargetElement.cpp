// Last updated: 4/14/2026, 12:29:38 AM
1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int n = nums.size();
5        int bestRight = INT_MAX;
6        for (int i = start; i < n; i++) {
7            if (nums[i] == target) {
8                bestRight = abs(i - start);
9                break;
10            }
11        }
12
13        int bestLeft = INT_MAX;
14        for (int i = start; i >= 0; i--) {
15            if (nums[i] == target) {
16                bestLeft = abs(i - start);
17                break;
18            }
19        }
20
21        return min(bestLeft, bestRight);
22    }
23};