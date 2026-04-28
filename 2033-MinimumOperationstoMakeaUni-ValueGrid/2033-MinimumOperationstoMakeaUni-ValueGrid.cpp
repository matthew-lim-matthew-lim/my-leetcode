// Last updated: 4/28/2026, 3:15:22 PM
1/* 
2Make the numbers equal to the median. 
3 */
4class Solution {
5public:
6    int minOperations(vector<vector<int>>& grid, int x) {
7        int n = grid.size();
8        int m = grid[0].size();
9
10        vector<int> vec(n*m, 0);
11        for (int i = 0; i < n; i++) {
12            for (int j = 0; j < m; j++) {
13                vec[i*m + j] = grid[i][j];
14            }
15        }
16        sort(vec.begin(), vec.end());
17
18        int expectedMod = vec[0] % x;
19
20        int res = 0;
21        for (int i = 0; i < vec.size(); i++) {
22            if ((vec[i] % x) != expectedMod) {
23                return -1;
24            }
25            res += (abs(vec[i] - vec[n*m / 2]) / x);
26        }
27
28        return res;
29    }
30};