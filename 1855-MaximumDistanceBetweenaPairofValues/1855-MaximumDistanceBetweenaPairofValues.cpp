// Last updated: 4/19/2026, 5:03:18 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
4        int p1 = nums1.size() - 1;
5        int p2 = nums2.size() - 1;
6
7        int res = 0;
8
9        while (p1 >= 0 && p2 >= 0) {
10            if (p1 <= p2 && nums1[p1] <= nums2[p2]) {
11                res = max(res, p2 - p1);
12                p1--;
13            } else if (p1 > p2) {
14                p1--;
15            } else if (nums1[p1] > nums2[p2]) {
16                p2--;
17            }
18        }
19        
20        return res;
21    }
22};