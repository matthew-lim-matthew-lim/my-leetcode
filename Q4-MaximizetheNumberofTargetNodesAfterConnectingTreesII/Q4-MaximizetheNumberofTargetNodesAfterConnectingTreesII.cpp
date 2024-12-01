class Solution {
public:
    // Return the number of odd distances and even distances from the start_node
    pair<int, int> bfs_max_depth(unordered_map<int, vector<int>>& graph, int start_node, unordered_map<int, bool>& even_graph) {
        // Pair of (node, depth)
        queue<pair<int, int>> q;
        unordered_map<int, bool> visited;

        unordered_map<int, int> num_even_odd;

        q.push({start_node, 0});
        
        visited[start_node] = true;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            num_even_odd[curr.second % 2]++;
            even_graph[curr.first] = curr.second % 2;
            q.pop();

            for (int neighbour : graph[curr.first]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push({neighbour, curr.second + 1});
                }
            }
        }

        return {num_even_odd[0], num_even_odd[1]};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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

        unordered_map<int, bool> even_graph_t2;
        pair<int, int> t2_pair_calc = bfs_max_depth(g2_graph, 0, even_graph_t2);
        int max_targets_t2 = max(t2_pair_calc.first, t2_pair_calc.second);

        unordered_map<int, bool> even_graph_t1;
        pair<int, int> t1_pair_calc = bfs_max_depth(g1_graph, 0, even_graph_t1);

        // Find the target reach for each node in tree 1
        for (int i = 0; i < edges1.size() + 1; i++) {
            if (even_graph_t1[i] == true) {
                res.push_back(t1_pair_calc.second + max_targets_t2);
            } else {
                res.push_back(t1_pair_calc.first + max_targets_t2);
            }
        }

        return res;
    }
};