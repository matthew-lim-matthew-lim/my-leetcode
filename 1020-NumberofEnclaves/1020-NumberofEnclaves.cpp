// Last updated: 4/27/2026, 6:44:06 PM
1/* 
2We can just union all the stuff at the boundary into the same group. 
3Then, union everything at the edges. 
4
5Or, we can just run BFS from everything at the boundaries. 
6
7All of the remaining 1's that are unvisited are included in the output. 
8 */
9class Solution {
10private:
11    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
12public:
13    int numEnclaves(vector<vector<int>>& grid) {
14        int n = grid.size();
15        int m = grid[0].size();
16
17        auto bfs = [&](int i, int j){
18            queue<pair<int, int>> q;
19            q.push({i, j});
20            grid[i][j] = 0;
21
22            while (!q.empty()) {
23                auto [y, x] = q.front();
24                q.pop();
25
26                for (pair<int, int> dir : directions) {
27                    if (y + dir.first >= n ||
28                        y + dir.first < 0 ||
29                        x + dir.second >= m ||
30                        x + dir.second < 0 ||
31                        grid[y + dir.first][x + dir.second] == 0
32                    ) {
33                        continue;
34                    }
35
36                    q.push({y + dir.first, x + dir.second});
37                    grid[y + dir.first][x + dir.second] = 0;
38                }
39            }
40        };
41
42        for (int i = 0; i < n; i++) {
43            if (grid[i][0]) {
44                bfs(i, 0);
45            }
46            if (grid[i][m-1]){
47                bfs(i, m-1);
48            }
49        }
50        for (int i = 1; i < m-1; i++) {
51            if (grid[0][i]) {
52                bfs(0, i);
53            }
54            if (grid[n-1][i]){
55                bfs(n-1, i);
56            }
57        }
58
59        // Find the number of 1's in grid.
60        int res = 0;
61
62        for (int i = 0; i < n; i++) {
63            for (int j = 0; j < m; j++) {
64                if (grid[i][j]) {
65                    res++;
66                }
67            }
68        }
69
70        return res;
71    }
72};