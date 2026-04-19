// Last updated: 4/19/2026, 1:13:34 PM
1/*
2Multi-source BFS. 
3
4Use a visited matrix with numbers.
5If the popped element has a smaller value, then ignore it. 
6If the popped element has a bigger value, then use that value.
7*/
8class Solution {
9public:
10    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
11        queue<vector<int>> q;
12
13        vector<vector<int>> res(n, vector<int>(m, 0));
14        vector<vector<int>> visited(n, vector<int>(m, false));
15
16        for (vector<int> &source : sources) {
17            q.push({ source[0], source[1], source[2], 1 });
18
19            res[source[0]][source[1]] = source[2];
20            visited[source[0]][source[1]] = 1;
21        }
22
23        while (!q.empty()) {
24            int y = q.front()[0];
25            int x = q.front()[1];
26            int c = q.front()[2];
27            int l = q.front()[3];
28            q.pop();
29
30            // cout << y << " " << x << " " << c << " " << l << endl;
31
32            if (res[y][x] > c) {
33                continue;
34            }
35
36            if (y + 1 < n && 
37                (!visited[y+1][x] || visited[y+1][x] == l+1) &&
38                res[y+1][x] < c
39            ) {
40                q.push({y+1, x, c, l+1});
41                res[y+1][x] = max(res[y+1][x], c);
42                visited[y+1][x] = l+1;
43            }
44            if (y - 1 >= 0 && 
45                (!visited[y-1][x] || visited[y-1][x] == l+1) &&
46                res[y-1][x] < c
47            ) {
48                q.push({y-1, x, c, l+1});
49                res[y-1][x] = max(res[y-1][x], c);
50                visited[y-1][x] = l+1;
51            }
52            if (x + 1 < m && 
53                (!visited[y][x+1] || visited[y][x+1] == l+1) &&
54                res[y][x+1] < c
55            ) {
56                q.push({y, x+1, c, l+1});
57                res[y][x+1] = max(res[y][x+1], c);
58                visited[y][x+1] = l+1;
59            }
60            if (x - 1 >= 0 && 
61                (!visited[y][x-1] || visited[y][x-1] == l+1) &&
62                res[y][x-1] < c
63            ) {
64                q.push({y, x-1, c, l+1});
65                res[y][x-1] = max(res[y][x-1], c);
66                visited[y][x-1] = l+1;
67            }
68        }
69        
70        // for (int i = 0; i < n; i++) {
71        //     for (int j = 0; j < m; j++) {
72        //         cout << visited[i][j] << " ";
73        //     }
74        //     cout << endl;
75        // }
76
77        return res;
78    }
79};