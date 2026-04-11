// Last updated: 4/11/2026, 12:23:56 PM
1class Solution {
2public: 
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size();
5
6        unordered_map<int, deque<int>> pMap;
7
8        int res = INT_MAX;
9
10        for (int i = 0; i < n; i++) {
11            if (pMap[nums[i]].size() >= 2) {
12                int k = pMap[nums[i]].front();
13                int j = pMap[nums[i]].back();
14                res = min(res, abs(i - j) + abs(j - k) + abs(k - i));
15
16                pMap[nums[i]].pop_front();
17            }
18
19            pMap[nums[i]].push_back(i);
20        }
21
22        return res == INT_MAX ? -1 : res;
23    }
24};