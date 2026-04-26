// Last updated: 4/26/2026, 11:39:42 PM
1class Solution {
2private:
3    vector<vector<int>> res;
4public:
5    void backtrack(vector<int> curr, unordered_map<int, bool> remaining) {
6        bool valid = false;
7        for (auto p : remaining) {
8            if (p.second) {
9                valid = true;
10
11                curr.push_back(p.first);
12                remaining[p.first] = false;
13                backtrack(curr, remaining);
14                remaining[p.first] = true;
15                curr.pop_back();
16            }
17        }
18
19        if (!valid) {
20            res.push_back(curr);
21        }
22    }
23
24    vector<vector<int>> permute(vector<int>& nums) {
25        unordered_map<int, bool> remaining;
26        for (int num : nums) {
27            remaining[num] = true;
28        }
29
30        backtrack({}, remaining);
31
32        return res;
33    }
34};