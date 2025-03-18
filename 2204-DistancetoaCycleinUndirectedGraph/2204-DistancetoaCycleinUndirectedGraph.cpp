class Solution {
public:
    int dfs(vector<vector<int>> &adjList, int curr, vector<int> &rank, int time, unordered_set<int> &cycleNodes, vector<bool> &visited) {
        if (rank[curr] != INT_MAX) {
            return rank[curr];
        }
        rank[curr] = time;

        int minRank = time + 1;

        for (int neigh : adjList[curr]) {
            if (rank[neigh] == time - 1) {
                // Parent of this node.
                continue;
            }

            int neighRank = dfs(adjList, neigh, rank, time + 1, cycleNodes, visited);

            if (neighRank <= time) {
                // Cycle
                cycleNodes.insert(curr);
                visited[curr] = true;
            }

            minRank = min(minRank, neighRank);
        }

        return minRank;
    }

    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        // Get the cycle using DFS.
        // Use BFS from the nodes in the cycle, to get the minimum distance to each node. 
        vector<vector<int>> adjList(n, vector<int>());
        for (vector<int> &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> rank(n, INT_MAX);
        int time;

        // DFS to find cycle
        unordered_set<int> cycleNodes;
        vector<bool> visited(n, false);
        dfs(adjList, 0, rank, time, cycleNodes, visited);

        // Start BFS from the nodes in the cycle
        vector<int> shortestDist(n, INT_MAX);
        for (int i : cycleNodes) {
            shortestDist[i] = 0;

            queue<pair<int, int>> q;
            q.push({ i, 0 });
            while (!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();
                int currNode = curr.first;
                int currDist = curr.second;
                shortestDist[currNode] = currDist;

                for (int neigh : adjList[currNode]) {
                    if (visited[neigh] == true) {
                        continue;
                    }
                    visited[neigh] = true;
                    q.push({ neigh, currDist + 1 });
                }
            }
        }

        return shortestDist;
    }
};