// Last updated: 4/26/2026, 10:53:08 PM
1class Solution {
2public:
3    vector<vector<int>> generate(int numRows) {
4        vector<vector<int>> res = {{1}};
5
6        for (int i = 1; i < numRows; i++) {
7            int l = -1;
8            int r = 0;
9            
10            vector<int> currRow;
11            for (; l < (int)res.back().size(); l++, r++) {
12                int lVal = l >= 0 ? res.back()[l] : 0;
13                int rVal = r < res.back().size() ? res.back()[r] : 0;
14
15                currRow.push_back(lVal + rVal);
16            }
17
18            res.push_back(currRow);
19        }
20
21        return res;
22    }
23};