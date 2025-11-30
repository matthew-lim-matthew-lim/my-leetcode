// Last updated: 11/30/2025, 7:24:31 PM
1/* 
2Seems like a simple Djikstras, except that Djikstras finds the shortest path, 
3and we want to find the longest path. 
4We can simply treat each edge like (6000 - weight). That is, shortest edges
5are less favourable. 
6Actually, that won't work, because if there is a more efficient path, the algorithm will take it. 
7
8The real solution would be to use BFS, and at each node keep track of the current time. We then only use the minimum time to each node. 
9And we keep going until the queue is empty. 
10If the queue is empty, and we visited all the nodes, we return an answer. 
11
12Visit a neighbour if 'curr + edge < dist[neigh]`.
13 */
14
15class Solution {
16public:
17    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
18        // Construct adjList
19        vector<vector<pair<int, int>>> adjList(n + 1, vector<pair<int, int>>());
20        for (vector<int> &time : times) {
21            adjList[time[0]].push_back({ time[2], time[1]});
22        }
23
24        // Algo
25        vector<int> dist(n + 1, INT_MAX);
26        dist[0] = 0;
27        dist[k] = 0;
28        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
29
30        pq.push({0, k});
31
32        while (!pq.empty()) {
33            auto [ d, u ] = pq.top();
34            pq.pop();
35
36            for (pair<int, int> &e : adjList[u]) {
37                int w = e.first;
38                int v = e.second;
39
40                if (dist[u] + w < dist[v]) {
41                    dist[v] = dist[u] + w;
42                    pq.push({dist[v], v});
43                }
44            }
45        }
46
47        // Return the longest distance
48        if (find(dist.begin(), dist.end(), INT_MAX) != dist.end()) {
49            return -1;
50        }
51
52        return *max_element(dist.begin(), dist.end());
53    }
54};