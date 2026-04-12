// Last updated: 4/12/2026, 3:16:35 PM
1class Solution {
2public:
3    vector<int> findDegrees(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        vector<int> res(n, 0);
6
7        for (int i = 0; i < n; i++) {
8            for (int j = 0; j < n; j++) {
9                if (matrix[i][j] == 1) {
10                    res[i]++;
11                }
12            }
13        }
14
15        return res;
16    }
17};