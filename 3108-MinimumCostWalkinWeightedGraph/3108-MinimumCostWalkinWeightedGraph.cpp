class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // Intentionally use edges with different bits. 
        // Use edges with high hamming distance. 
        // An AND will never make a number that is bigger. 
        // AND all of the edges in each connected component. 

        // Use BFS to group each node into a connected component. 
        // Then, AND all the edges connected to those nodes, to get a weight W.
        // The minimum distance from each node to each other i the connected graph 
        // is W.

        // Each entry is { nodeId, weight }
        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());
        for (vector<int> &edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        unordered_map<int, int> componentMap;
        vector<int> componentWeights;

        int componentCount = -1;

        unordered_set<int> visited;
        for (int i = 0; i < n; i++) {
            if (visited.contains(i)) {
                continue;
            }

            componentCount++;

            unordered_set<int> currComponent;

            queue<int> q;
            q.push(i);

            int componentWeight = INT_MAX;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                componentMap[curr] = componentCount;

                for (auto neigh : adjList[curr]) {
                    int neighNode = neigh.first;
                    int neighWeight = neigh.second;
                    
                    componentWeight &= neighWeight; 
                    
                    if (visited.contains(neighNode)) {
                        continue;
                    }

                    visited.insert(neighNode);
                    q.push(neighNode);
                }
            }

            // Give all currcomponents the same distance. 
            componentWeights.push_back(componentWeight);
        }

        // Process the queries.
        vector<int> res(query.size(), -1);
        for (int i = 0; i < query.size(); i++) {
            int src = query[i][0];
            int dst = query[i][1];

            if (componentMap[src] != componentMap[dst]) {
                continue;
            }

            res[i] = componentWeights[componentMap[src]];
        }

        return res;
    }
};