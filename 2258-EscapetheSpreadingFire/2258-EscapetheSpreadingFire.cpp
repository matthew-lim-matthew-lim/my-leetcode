// Last updated: 4/26/2026, 12:01:16 AM
1/* 
2Binary Search + BFS
3 */
4class Solution {
5private:
6    int n;
7    int m;
8    vector<vector<int>> grid_;
9
10    struct QEntry {
11        int y;
12        int x;
13        int t;
14    };
15public:
16    bool f(int mid) {
17        // cout << mid << endl;
18        vector<vector<int>> currGrid(grid_);
19        vector<vector<bool>> visited(n, vector<bool>(m, false));
20
21        queue<QEntry> q;
22        q.push(QEntry{
23            0,
24            0,
25            mid
26        });
27        visited[0][0] = true;
28
29        while (!q.empty()) {
30            int y = q.front().y;
31            int x = q.front().x;
32            int t = q.front().t;
33            q.pop();
34
35            // cout << y << " " << x << " " << t << endl;
36 
37            if (y==n-1 && x==m-1) {
38                return true;
39            }
40
41            if (y+1<n && (currGrid[y+1][x] > t+1 || 
42                (y+1 == n-1 && x == m-1 && currGrid[y+1][x] == t+1)) && 
43                !visited[y+1][x]
44            ) {
45                visited[y+1][x] = true;
46                q.push(QEntry{
47                    y+1,
48                    x,
49                    t+1
50                });
51            }
52            if (y-1>=0 && (currGrid[y-1][x] > t+1 || 
53                (y-1 == n-1 && x == m-1 && currGrid[y-1][x] == t+1)) && 
54                !visited[y-1][x]
55            ) {
56                visited[y-1][x] = true;
57                q.push(QEntry{
58                    y-1,
59                    x,
60                    t+1
61                });
62            }
63            if (x+1<m && (currGrid[y][x+1] > t+1 || 
64                (y == n-1 && x+1 == m-1 && currGrid[y][x+1] == t+1)) && 
65                !visited[y][x+1]
66            ) {
67                visited[y][x+1] = true;
68                q.push(QEntry{
69                    y,
70                    x+1,
71                    t+1
72                });
73            }
74            if (x-1>=0 && (currGrid[y][x-1] > t+1 || 
75                (y == n-1 && x-1 == m-1 && currGrid[y][x-1] == t+1)) && 
76                !visited[y][x-1]
77            ) {
78                visited[y][x-1] = true;
79                q.push(QEntry{
80                    y,
81                    x-1,
82                    t+1
83                });
84            }
85
86            // for (int i = 0; i < n; i++) {
87            //     for (int j = 0; j < m; j++) {
88            //         cout << currGrid[i][j];
89            //     }
90            //     cout << endl;
91            // }
92            // cout << endl;
93        }
94
95        return false;
96    }
97
98    int maximumMinutes(vector<vector<int>>& grid) {
99        n = grid.size();
100        m = grid[0].size();
101
102        queue<QEntry> q;
103        for (int i = 0; i < n; i++) {
104            for (int j = 0; j < m; j++) {
105                if (grid[i][j] == 1) {
106                    q.push(QEntry{
107                        i,
108                        j,
109                        0
110                    });
111                } else if (grid[i][j] == 2) {
112                    grid[i][j] = -1;
113                } else if (grid[i][j] == 0) {
114                    grid[i][j] = INT_MAX;
115                }
116            }
117        }
118
119        while (!q.empty()) {
120            int y = q.front().y;
121            int x = q.front().x;
122            int t = q.front().t;
123
124            q.pop();
125
126            if (y+1<n && grid[y+1][x] == INT_MAX) {
127                grid[y+1][x] = t+1;
128                q.push(QEntry{
129                    y+1,
130                    x,
131                    t+1
132                });
133            }
134            if (y-1>=0 && grid[y-1][x] == INT_MAX) {
135                grid[y-1][x] = t+1;
136                q.push(QEntry{
137                    y-1,
138                    x,
139                    t+1
140                });
141            }
142            if (x+1<m && grid[y][x+1] == INT_MAX) {
143                grid[y][x+1] = t+1;
144                q.push(QEntry{
145                    y,
146                    x+1,
147                    t+1
148                });
149            }
150            if (x-1>=0 && grid[y][x-1] == INT_MAX) {
151                grid[y][x-1] = t+1;
152                q.push(QEntry{
153                    y,
154                    x-1,
155                    t+1
156                });
157            }
158        }
159
160        // for (int i = 0; i < n; i++) {
161        //     for (int j = 0; j < m; j++) {
162        //         cout << grid[i][j] << " ";
163        //     }
164        //     cout << endl;
165        // }
166        // cout << endl;
167
168        grid_ = grid;
169
170        int lo = 0;
171        int hi = n*m;
172        int bestSoFar = -1;
173
174        while (lo <= hi) {
175            int mid = (lo + hi) / 2;
176            if (f(mid)) {
177                bestSoFar = mid;
178                lo = mid + 1;
179            } else {
180                hi = mid - 1;
181            }
182        }
183
184        return bestSoFar == n*m ? 1'000'000'000 : bestSoFar;
185    }
186};