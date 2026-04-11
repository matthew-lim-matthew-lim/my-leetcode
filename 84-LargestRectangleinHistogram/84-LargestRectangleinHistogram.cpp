// Last updated: 4/11/2026, 2:34:01 PM
1/* 
2Monotonicity:
3If there is a decrease in height, then we can discard the oldest height. 
4
5map<height, index> heightMap;
6
7If the newest height is lower, we remove all the heights that are higher from hieghMap, 
8before continuing to process. 
9
10Or I can just use a double for loop.
11
12---
13Original monotoic idea.
14At the end, resolve all the heights. 
15 */
16
17class Solution {
18public:
19    int largestRectangleArea(vector<int>& heights) {
20        heights.push_back(0);
21
22        int n = heights.size();
23
24        stack<pair<int, int>> stk;
25
26        int res = 0;
27
28        for (int i = 0; i < n; i++) {
29            // Add a new number that is smaller.
30            pair<int, int> currEntry = {heights[i], i};
31            while (!stk.empty() &&
32                stk.top().first > heights[i]
33            ) {
34                currEntry = stk.top();
35                stk.pop();
36                res = max(res, currEntry.first * (i - currEntry.second));
37            }
38
39            if (currEntry.first != -1) {
40                currEntry.first = heights[i];
41                stk.push(currEntry);
42            }
43        }
44
45        return res;
46    }
47};