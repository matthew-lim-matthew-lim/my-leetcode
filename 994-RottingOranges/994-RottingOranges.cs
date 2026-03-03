// Last updated: 3/3/2026, 9:34:13 PM
1/* 
2Go through the grid, and mark the adjacent fresh ones as 3,
3which means "delete next", mark them in an unordered_map.
4When the grid has been explored, go through the unordered_map and 
5carry out the deletions. 
6Then, repeat the process. 
7 */
8public class Solution {
9    public class Coord {
10        public int Y { get; set; }
11        public int X { get; set; }
12        public Coord(int y, int x) { Y = y; X = x; }
13    }
14
15    public int OrangesRotting(int[][] grid) {
16        int n = grid.Length;
17        int m = grid[0].Length;
18
19        var nextRotten = new HashSet<Coord>();
20
21        bool changed = true;
22        int res = 0;
23
24        while (changed) {
25            changed = false;
26
27            for (int i = 0; i < n; i++) {
28                for (int j = 0; j < m; j++) {
29                    if (grid[i][j] == 2) {
30                        if (i-1 >= 0 && grid[i-1][j] == 1) {
31                            nextRotten.Add(new Coord(i-1, j));
32                            changed = true;
33                        }
34                        if (i+1 < n && grid[i+1][j] == 1) {
35                            nextRotten.Add(new Coord(i+1, j));
36                            changed = true;
37                        }
38                        if (j-1 >= 0 && grid[i][j-1] == 1) {
39                            nextRotten.Add(new Coord(i, j-1));
40                            changed = true;
41                        }
42                        if (j+1 < m && grid[i][j+1] == 1) {
43                            nextRotten.Add(new Coord(i, j+1));
44                            changed = true;
45                        }
46                    }
47                }
48            }
49
50            if (changed) {
51                res++;
52            }
53
54            foreach (Coord c in nextRotten) {
55                grid[c.Y][c.X] = 2;
56            }
57        }
58
59            for (int i = 0; i < n; i++) {
60                for (int j = 0; j < m; j++) {
61                    if (grid[i][j] == 1) {
62                        return -1;
63                    }
64                }
65            }
66
67        return res;
68    }
69}