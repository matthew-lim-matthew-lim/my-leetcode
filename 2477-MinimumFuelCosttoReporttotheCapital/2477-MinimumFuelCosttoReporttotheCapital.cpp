// Last updated: 11/30/2025, 6:38:45 PM
1/* 
2For each node, go the the children. For each child, count the number of children. 
3
42 has no children -> 0 (no path)
53 has 1 child -> 1 (path 3-2): 1 / 2 = 1
61 has 2 chldren -> 2 (path 1-3): 2 / 2 = 1
70 has a child 1, that is together 3 children -> 3 (path 0-1): 3 / 2 = 2
8
91 + 2 + 3
10
11BFS from the leaf nodes (nodes with only 1 edge);
12Use a queue. 
13Assign nodes a weight (unordered_map). 
14
15Eg. Enqueue 2, 5, 6. 
16Pop 2. 
172 is popped, meaning that it has no more incoming edges, we can now process its weight. 
18res += (weight of 2) / seats;
19Neighbour is 3, add the weight of node 2 to node 3. Node 3 is now weight 2. Enqeue 3. 
20
21Edit:
22You probably need to do it in topological order for it to work correctly. This is kind of hard. 
23
24Using Kahns algorithm we can lowkey do it. 
25
26Fixes to key difficulties I got to:
27- Every vertex starts with weight 1.
28- Regardless if we enqueue the next node or not, we add the current node weight into the next node. 
29 */
30
31class Solution {
32public:
33    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
34        // Make adjacency list
35        int n = roads.size() + 1;
36        vector<vector<int>> adjList(n, vector<int>());
37        vector<int> indegree(n, 0);
38        for (vector<int> &road : roads) {
39            adjList[road[0]].push_back(road[1]);
40            adjList[road[1]].push_back(road[0]);
41            indegree[road[0]]++;
42            indegree[road[1]]++;
43        }
44
45        // Kahns algorithm
46        vector<long long> nodeWeight(n, 0);
47
48        queue<int> q;
49        for (int i = 1; i < n; i++) {
50            if (indegree[i] == 1) {
51                q.push(i);
52            }
53            nodeWeight[i] = 1;
54        }
55
56        long long res = 0;
57        vector<int> topo;
58        while (!q.empty()) {
59            int u = q.front();
60            q.pop();
61
62            topo.push_back(u);
63
64            res += (nodeWeight[u] + seats - 1) / seats;
65
66            // cout << u << ", " << ceil(nodeWeight[u] / 2.0) << endl;
67
68            for (int v : adjList[u]) {
69                if (indegree[v] > 0) {
70                    if (--indegree[v] == 1 && v != 0) {
71                        // Process the node
72                        q.push(v);
73                    }
74                    nodeWeight[v] += nodeWeight[u];
75                }
76            }
77        }
78
79        for (int i = 0; i < nodeWeight.size(); i++) {
80            // cout << i << ", " << nodeWeight[i] << endl;
81        }
82
83        for (int v : topo) {
84            // cout << v << endl;
85        }
86
87        return res;
88    }
89};