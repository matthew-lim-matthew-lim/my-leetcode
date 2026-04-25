// Last updated: 4/25/2026, 8:47:04 PM
1class Solution {
2public:
3    int minimumEffortPath(vector<vector<int>>& heights) {
4        int n = heights.size();
5        int m = heights[0].size();
6
7        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));
8        minCost[0][0] = 0;
9
10        priority_queue<
11            pair<int, pair<int, int>>, 
12            vector<pair<int, pair<int, int>>>, 
13            greater<>
14        > pq;
15
16        pq.push({
17            0,
18            {0, 0}
19        });
20
21        while (!pq.empty()) {
22            int d = pq.top().first;
23            int y = pq.top().second.first;
24            int x = pq.top().second.second;
25            pq.pop();
26
27            if (minCost[y][x] < d) {
28                continue;
29            }
30
31            if (y+1<n && minCost[y+1][x] > max(d, abs(heights[y+1][x] - heights[y][x]))) {
32                minCost[y+1][x] = max(d, abs(heights[y+1][x] - heights[y][x]));
33                pq.push({
34                    minCost[y+1][x],
35                    {y+1, x}
36                });
37            }
38
39            if (y-1>=0 && minCost[y-1][x] > max(d, abs(heights[y-1][x] - heights[y][x]))) {
40                minCost[y-1][x] = max(d, abs(heights[y-1][x] - heights[y][x]));
41                pq.push({
42                    minCost[y-1][x],
43                    {y-1, x}
44                });
45            }
46
47            if (x+1<m && minCost[y][x+1] > max(d, abs(heights[y][x+1] - heights[y][x]))) {
48                minCost[y][x+1] = max(d, abs(heights[y][x+1] - heights[y][x]));
49                pq.push({
50                    minCost[y][x+1],
51                    {y, x+1}
52                });
53            }
54
55            if (x-1>=0 && minCost[y][x-1] > abs(heights[y][x-1] - heights[y][x])) {
56                minCost[y][x-1] = max(d, abs(heights[y][x-1] - heights[y][x]));
57                pq.push({
58                    minCost[y][x-1],
59                    {y, x-1}
60                });
61            }
62        }
63
64        return minCost[n-1][m-1];
65    }
66};