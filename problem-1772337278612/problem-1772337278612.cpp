// Last updated: 3/1/2026, 2:54:38 PM
1class Solution {
2public:
3    int minimumOR(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        int ans = 0;
7
8        for (int b = 29; b >= 0; b--) {
9            int test_mask = ans | ((1 << b) - 1);
10            
11            bool possible = true;
12
13            for (int i = 0; i < n; i++) {
14                bool found_in_row = false;
15                for (int x : grid[i]) {
16                    if ((x | test_mask) == test_mask) {
17                        found_in_row = true;
18                        break;
19                    }
20                }
21                if (!found_in_row) {
22                    possible = false;
23                    break;
24                }
25            }
26
27            if (!possible) {
28                ans |= (1 << b);
29            }
30        }
31
32        return ans;
33    }
34};