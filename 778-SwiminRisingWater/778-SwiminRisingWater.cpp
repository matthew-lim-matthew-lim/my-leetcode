// Last updated: 4/27/2026, 4:38:10 PM
1/* 
2Can we just union find until the start and end squares are in the same group? 
3 */
4class UnionFind {
5private:
6    vector<int> parent;
7    vector<int> rank;
8public:
9    UnionFind(int n) {
10        parent.resize(n);
11        iota(parent.begin(), parent.end(), 0);
12        rank.resize(n);
13    }
14
15    int find(int a) {
16        if (a == parent[a]) {
17            return a;
18        }
19
20        return parent[a] = find(parent[a]);
21    }
22
23    void join(int a, int b) {
24        int rootA = find(a);
25        int rootB = find(b);
26
27        if (rootA == rootB) {
28            return;
29        }
30
31        if (rank[rootA] > rank[rootB]) {
32            parent[rootB] = rootA;
33        } else if (rank[rootB] > rank[rootA]) {
34            parent[rootA] = rootB;
35        } else {
36            parent[rootB] = rootA;
37            rank[rootA]++;
38        }
39    }
40};
41
42class Solution {
43private:
44    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
45
46public:
47    int swimInWater(vector<vector<int>>& grid) {
48        int n = grid.size();
49
50        if (n == 1) {
51            return grid[0][0];
52        }
53
54        UnionFind uf(n*n);
55
56        priority_queue<
57            pair<int, pair<int, int>>, 
58            vector<pair<int, pair<int, int>>>, 
59            greater<>
60        > pq;
61
62        for (int i = 0; i < n; i++) {
63            for (int j = 0; j < n; j++) {
64                pq.push({grid[i][j], {i, j}});
65            }
66        }
67
68        while (!pq.empty()) {
69            int level = pq.top().first;
70            auto [y, x] = pq.top().second;
71            pq.pop();
72
73            for (pair<int, int> dir : directions) {
74                if (y + dir.first >= n ||
75                    y + dir.first < 0 ||
76                    x + dir.second >= n ||
77                    x + dir.second < 0
78                ) {
79                    continue;
80                }
81
82                if (grid[y + dir.first][x + dir.second] > grid[y][x]) {
83                    continue;
84                }
85
86                uf.join(y * n + x, (y + dir.first) * n + (x + dir.second));
87
88                if (uf.find(0) == uf.find(n * n - 1)) {
89                    return level;
90                }
91            }
92        }
93
94        return -1;
95    }
96};