// Last updated: 11/30/2025, 6:37:39 PM
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
25 */
26
27class Solution {
28public:
29    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
30        // Make adjacency list
31        int n = roads.size() + 1;
32        vector<vector<int>> adjList(n, vector<int>());
33        vector<int> indegree(n, 0);
34        for (vector<int> &road : roads) {
35            adjList[road[0]].push_back(road[1]);
36            adjList[road[1]].push_back(road[0]);
37            indegree[road[0]]++;
38            indegree[road[1]]++;
39        }
40
41        // Kahns algorithm
42        vector<long long> nodeWeight(n, 0);
43
44        queue<int> q;
45        for (int i = 1; i < n; i++) {
46            if (indegree[i] == 1) {
47                q.push(i);
48            }
49            nodeWeight[i] = 1;
50        }
51
52        long long res = 0;
53        vector<int> topo;
54        while (!q.empty()) {
55            int u = q.front();
56            q.pop();
57
58            topo.push_back(u);
59
60            res += (nodeWeight[u] + seats - 1) / seats;
61
62            // cout << u << ", " << ceil(nodeWeight[u] / 2.0) << endl;
63
64            for (int v : adjList[u]) {
65                if (indegree[v] > 0) {
66                    if (--indegree[v] == 1 && v != 0) {
67                        // Process the node
68                        q.push(v);
69                    }
70                    nodeWeight[v] += nodeWeight[u];
71                }
72            }
73        }
74
75        for (int i = 0; i < nodeWeight.size(); i++) {
76            // cout << i << ", " << nodeWeight[i] << endl;
77        }
78
79        for (int v : topo) {
80            // cout << v << endl;
81        }
82
83        return res;
84    }
85};