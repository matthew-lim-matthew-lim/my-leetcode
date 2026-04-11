// Last updated: 4/11/2026, 4:32:18 PM
1/* 
2We can use the solution for "Largest Rectangle in Histogram".
3Just run that on every row, facing upwards.
4 */
5class Solution {
6public:
7    int largestRectangleArea(vector<int>& heights) {
8        heights.push_back(0);
9
10        int n = heights.size();
11
12        stack<pair<int, int>> stk;
13
14        int res = 0;
15
16        for (int i = 0; i < n; i++) {
17            // Add a new number that is smaller.
18            pair<int, int> currEntry = {heights[i], i};
19            while (!stk.empty() &&
20                stk.top().first > heights[i]
21            ) {
22                currEntry = stk.top();
23                stk.pop();
24                res = max(res, currEntry.first * (i - currEntry.second));
25            }
26
27            if (currEntry.first != -1) {
28                currEntry.first = heights[i];
29                stk.push(currEntry);
30            }
31        }
32
33        return res;
34    }
35
36    int maximalRectangle(vector<vector<char>>& matrix) {
37        int n = matrix.size();
38        int m = matrix[0].size();
39
40        vector<int> curr(m, 0);
41
42        int res = 0;
43        for (int row = 0; row < n; row++) {
44            for (int i = 0; i < m; i++) {
45                if (matrix[row][i] == '1') {
46                    curr[i]++;
47                } else {
48                    curr[i] = 0;
49                }
50            }
51            res = max(res, largestRectangleArea(curr));
52        }
53
54        return res;
55    }
56};