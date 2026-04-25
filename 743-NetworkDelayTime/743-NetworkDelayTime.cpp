// Last updated: 4/25/2026, 8:00:29 PM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<vector<vector<int>>> adjList(n);
5        for (const vector<int> &time : times) {
6            adjList[time[0]-1].push_back({ time[1]-1, time[2] });
7        }
8
9        vector<int> res(n, INT_MAX);
10        res[k-1] = 0;
11
12        priority_queue<vector<int>> pq;
13        pq.push({0, k-1});
14
15        while (!pq.empty()) {
16            int d = pq.top()[0];
17            int u = pq.top()[1];
18            pq.pop();
19
20            if (res[u] < d) {
21                continue;
22            }
23
24            for (const vector<int> &neigh : adjList[u]) {
25                int v = neigh[0];
26                int w = neigh[1];
27
28                if (res[v] > res[u] + w) {
29                    res[v] = res[u] + w;
30                    pq.push({
31                        res[u] + w,
32                        v
33                    });
34                }
35            }
36        }
37
38        int finalRes = *max_element(res.begin(), res.end());
39
40        return finalRes == INT_MAX ? -1 : finalRes;
41    }
42};