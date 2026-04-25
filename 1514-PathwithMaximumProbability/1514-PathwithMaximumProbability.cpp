// Last updated: 4/25/2026, 8:29:16 PM
1class Solution {
2public:
3    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
4        vector<vector<pair<int, double>>> adjList(n);
5
6        for (int i = 0; i < edges.size(); i++) {
7            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
8            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
9        }
10
11        priority_queue<pair<double, int>> pq;
12
13        vector<double> res(n, 0);
14        res[start_node] = 1;
15
16        pq.push({1.0, start_node});
17
18        while (!pq.empty()) {
19            double d = pq.top().first;
20            int u = pq.top().second;
21            pq.pop();
22
23            if (res[u] > d) continue;
24
25            for (pair<int, double> neigh : adjList[u]) {
26                double w = neigh.second;
27                int v = neigh.first;
28
29                if (res[v] < (res[u] * w)) {
30                    res[v] = (res[u] * w);
31                    pq.push({(res[u] * w), v});
32                }
33            }
34        }
35
36        return res[end_node];
37    }
38};