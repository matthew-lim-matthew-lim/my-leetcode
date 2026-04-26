// Last updated: 4/27/2026, 12:32:21 AM
1/* 
2DFS.
3 */
4class Solution {
5public:
6    bool containsCycle(vector<vector<char>>& grid) {
7        int n = grid.size();
8        int m = grid[0].size();
9
10        vector<vector<int>> visited(n, vector<int>(m, 0));
11
12        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
13
14        int visitTime = 1;
15        for (int i = 0; i < n; i++) {
16            for (int j = 0; j < m; j++) {
17                if (visited[i][j]) {
18                    continue;
19                }
20
21                char thisColour = grid[i][j];
22
23                queue<pair<pair<int, int>, pair<int, int>>> q;
24                q.push({{i, j}, {-1, -1}});
25
26                visited[i][j] = visitTime;
27
28                while (!q.empty()) {
29                    auto [y, x] = q.front().first;
30                    auto [parentY, parentX] = q.front().second;
31                    q.pop();
32
33                    for (pair<int, int> dir : directions) {
34                        if (y + dir.first >= n || 
35                            y + dir.first < 0 ||
36                            x + dir.second >= m ||
37                            x + dir.second < 0
38                        ) {
39                            continue;
40                        }
41
42                        if (grid[y + dir.first][x + dir.second] == thisColour &&
43                            (parentY != y + dir.first || parentX != x + dir.second)
44                        ) {
45                            if (visited[y + dir.first][x + dir.second]) {
46                                return true;
47                            } else {
48                                q.push({{y + dir.first, x + dir.second}, {y, x}});
49                                visited[y + dir.first][x + dir.second] = visitTime;
50                            }
51                        }
52                    }
53                }
54                visitTime++;
55            }
56        }
57
58        return false;
59    }
60};