// Last updated: 4/20/2026, 11:59:58 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5
6        int res = 0;
7        for (int i = 0; i < n; i++) {
8            for (int j = i+1; j < n; j++) {
9                if (colors[i] != colors[j]) {
10                    res = max(res, j - i);
11                }
12            }
13        }
14
15        return res;
16    }
17};