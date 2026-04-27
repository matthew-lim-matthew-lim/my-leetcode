// Last updated: 4/27/2026, 2:30:48 PM
1/* 
2[1, 5]
3[2, 3]
4 */
5class Solution {
6public:
7    vector<vector<int>> merge(vector<vector<int>>& intervals) {
8        sort(intervals.begin(), intervals.end());
9
10        vector<vector<int>> res;
11
12        for (const vector<int> &interval : intervals) {
13            if (res.empty()) {
14                res.push_back(interval);
15                continue;
16            }
17
18            if (res.back()[1] >= interval[0]) {
19                res.back()[1] = max(res.back()[1], interval[1]);
20            } else {
21                res.push_back(interval);
22            }
23        }
24
25        return res;
26    }
27};