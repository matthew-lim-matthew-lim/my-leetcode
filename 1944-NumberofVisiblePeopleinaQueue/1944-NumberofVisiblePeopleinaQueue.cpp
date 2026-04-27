// Last updated: 4/27/2026, 3:44:36 PM
1/* 
2- This is Shorter: res[i] = 1. Push this one. 
3- This is Taller: res[i] = stk.size(). Pop all shorter from the stack, and push this one. 
4 */
5class Solution {
6public:
7    vector<int> canSeePersonsCount(vector<int>& heights) {
8        stack<int> stk;
9
10        int n = heights.size();
11
12        vector<int> res(n, 0);
13
14        for (int i = n-1; i >= 0; i--) {
15            if (stk.empty()) {
16                res[i] = 0;
17                stk.push(heights[i]);
18                continue;
19            }
20
21            int popCount = 0;
22            while (!stk.empty() && stk.top() <= heights[i]) {
23                stk.pop();
24                popCount++;
25            }
26            if (!stk.empty()) {
27                popCount++;
28            }
29            res[i] = popCount;
30            stk.push(heights[i]);
31        }
32
33        return res;
34    }
35};