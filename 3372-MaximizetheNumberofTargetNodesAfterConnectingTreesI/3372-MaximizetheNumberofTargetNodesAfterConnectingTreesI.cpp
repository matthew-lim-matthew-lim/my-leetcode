// Last updated: 5/28/2025, 2:37:47 PM
class Solution {
public:
    int bfs_max_depth(unordered_map<int, vector<int>>& graph, int start_node, int max_depth) {
        if (max_depth < 0) {
            return 0;
        }
        
        // Pair of (node, depth)
        queue<pair<int, int>> q;
        unordered_map<int, bool> visited;

        q.push({start_node, 1});
        visited[start_node] = true;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            if (curr.second > max_depth) {
                continue;
            }

            for (int neighbour : graph[curr.first]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push({neighbour, curr.second + 1});
                }
            }
        }

        return visited.size();
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // Just get the node from tree 2 that has the most number of nodes in depth `k-1`. 
        // Then, attach all the nodes from tree 1 to that node in tree 2.

        vector<int> res;

        // Make the graphs into adjacency lists
        unordered_map<int, vector<int>> g1_graph;
        for (vector<int>& edge : edges1) {
            g1_graph[edge[0]].push_back(edge[1]);
            g1_graph[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, vector<int>> g2_graph;
        for (vector<int>& edge : edges2) {
            g2_graph[edge[0]].push_back(edge[1]);
            g2_graph[edge[1]].push_back(edge[0]);
        }

        // Find the ideal node in tree 2
        int max_targets_t2 = 0;
        for (pair<const int, vector<int>>& entry : g2_graph) {
            max_targets_t2 = max(max_targets_t2, bfs_max_depth(g2_graph, entry.first, k - 1));
        }

        // Find the target reach for each node in tree 1
        for (int i = 0; i < edges1.size() + 1; i++) {
            res.push_back(max_targets_t2 + bfs_max_depth(g1_graph, i, k));
        }

        return res;
    }
};