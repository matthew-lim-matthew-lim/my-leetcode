// Last updated: 12/2/2025, 12:14:33 AM
1/* 
2Breath first search?
3
4Keep track of the actual direction of an edge, but store them as bidirectional.
5
6Visited list.
7 */
8class Solution {
9public:
10    int minReorder(int n, vector<vector<int>>& connections) {
11        vector<vector<pair<int, bool>>> adjList(n, vector<pair<int, bool>>());
12
13        for (vector<int> &e : connections) {
14            adjList[e[0]].push_back({ e[1], false });
15            adjList[e[1]].push_back({ e[0], true });
16        }
17
18        unordered_set<int> visited;
19        visited.insert(0);
20        queue<int> q;
21        q.push(0);
22
23        int res = 0;
24
25        while (!q.empty()) {
26            int u = q.front();
27            q.pop();
28
29            for (pair<int, bool> p : adjList[u]) {
30                int v = p.first;
31                bool normDir = p.second;
32                if (!visited.contains(v)) {
33                    if (!normDir) {
34                        res++;
35                    }
36                    visited.insert(v);
37                    q.push(v);
38                }
39            }
40        }
41
42        return res;
43    }
44};