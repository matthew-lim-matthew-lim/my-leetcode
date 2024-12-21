class Solution {
public:
    int dfs(unordered_set<int>& visited, int curr, int prev, int& res, vector<int>& values, int k, unordered_map<int, vector<int>>& edge_map) {
        // cout << "curr: " << curr << ", prev: " << prev << endl;
        // cout << "edge_map[curr].size(): " << edge_map[curr].size() << endl;
        // cout << "values[curr]: " << values[curr] << endl;
        // for (int i = edge_map[curr].size() - 1; i >= 0; i--) {
        //     cout << edge_map[curr][i] << " ";
        // }
        // cout << endl;

        // edge_map[curr].size() == 1 tells us we are at a leaf. 
        if (edge_map[curr].size() == 1) {
            // if (values[curr] % k == 0) {
            //     res++;
            //     return;
            // } else {
            //     values[prev] += values[curr];
            //     return;
            // }
            return values[curr];
        }

        for (int next_node : edge_map[curr]) {
            if (visited.contains(next_node)) continue;
            visited.insert(next_node);
            int val = dfs(visited, next_node, curr, res, values, k, edge_map);
            if (val % k == 0) {
                res++;
            } else {
                values[curr] += val % k;
                values[next_node] = 0;
            }
        }
        return values[curr];
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Recursively see if a node can make a connected component. 
        // If a leaf node is not divisible by k, it must be in the same component as its parent node so we merge it with its parent node.
        // Since the sum of values is divisible by k, if a leaf node it divisible by k, then the remaining nodes in the tree (not in
        // the leaf) must also be divisible by k. 

        // Use DFS because we use a stack. 
        // If the leaf node has no children and not divisible by k, merge it with the parent. Since there is merging, we'd want it
        // to backtrack. 
        
        unordered_map<int, vector<int>> edge_map;
        for (vector<int>& edge : edges) {
            // if (edge[1] != 0) edge_map[edge[0]].push_back(edge[1]);
            // if (edge[0] != 0) edge_map[edge[1]].push_back(edge[0]);
            edge_map[edge[0]].push_back(edge[1]);
            edge_map[edge[1]].push_back(edge[0]);
        }

        // Maybe keep a visited set. 
        unordered_set<int> visited;
        int res = 1;
        visited.insert(0);
        // dfs(visited, 0, -1, res, values, k, edge_map);

        int curr = 0;
        for (int next_node : edge_map[curr]) {
            if (visited.contains(next_node)) continue;
            visited.insert(next_node);
            int val = dfs(visited, next_node, curr, res, values, k, edge_map);
            if (val % k == 0) {
                res++;
            } else {
                values[curr] += val % k;
                values[next_node] = 0;
            }
        }

        // for (int val : values) {
        //     cout << val << ' ';
        // }

        return res;
    }
};