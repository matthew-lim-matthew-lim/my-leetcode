// Last updated: 3/4/2026, 12:30:29 PM
1public class Solution {
2    public int NumSpecial(int[][] mat) {
3        int n = mat.Length;
4        int m = mat[0].Length;
5
6        int res = 0;
7
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (mat[i][j] == 0) {
11                    continue;
12                }
13
14                bool valid = true;
15
16                for (int y = 0; y < n; y++) {
17                    if (y == i) {
18                        continue;
19                    }
20
21                    if (mat[y][j] == 1) {
22                        valid = false;
23                        break;
24                    }
25                }
26
27                for (int x = 0; x < m; x++) {
28                    if (x == j) {
29                        continue;
30                    }
31
32                    if (mat[i][x] == 1) {
33                        valid = false;
34                        break;
35                    }
36                }
37
38                if (valid) {
39                    res++;
40                }
41            }
42        }
43
44        return res;
45    }
46}