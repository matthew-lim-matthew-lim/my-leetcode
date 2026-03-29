// Last updated: 3/29/2026, 2:52:48 PM
1/* 
2Just use a multiset?
3*/
4class Solution {
5public:
6    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
7        int n = nums.size();
8        multiset<int> window;
9        for (int i = 0; i < k; i++) {
10            window.insert(nums[i]);
11        }
12
13        vector<int> res = { *prev(window.end()) };
14
15        for (int i = k; i < n; i++) {
16            window.erase(window.find(nums[i-k]));
17            window.insert(nums[i]);
18            res.push_back(*prev(window.end()));
19        } 
20
21        return res;
22    }
23};