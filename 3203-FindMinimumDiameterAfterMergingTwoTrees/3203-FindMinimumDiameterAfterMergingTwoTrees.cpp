class Solution {
public:
    int diameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj_list;
        for (vector<int>& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // BFS uses a queue
        queue<int> q;
        unordered_set<int> visited;
        unordered_map<int, int> dist;

        // Conduct 1st BFS to find the furthest node. 
        q.push(0);
        visited.insert(0);
        dist[0] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int node : adj_list[curr]) {
                dist[node] = dist[curr] + 1;
                if (!visited.contains(node)) q.push(node);
                visited.insert(node);
            }
        }

        // Set `y` to be the furthest node from `x`
        int furthest_node = 0;
        int furthest_dist = 0;
        for (pair<int, int> p : dist) {
            if (p.second > furthest_dist) {
                furthest_node = p.first;
                furthest_dist = p.second;
            }
        }

        // Conduct 2nd BFS to find the diameter. 
        visited.clear();
        dist.clear();
        q.push(furthest_node);
        visited.insert(furthest_node);
        dist[furthest_node] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int node : adj_list[curr]) {
                dist[node] = dist[curr] + 1;
                if (!visited.contains(node)) q.push(node);
                visited.insert(node);
            }
        }

        furthest_dist = 0;
        for (pair<int, int> p : dist) {
            furthest_dist = max(furthest_dist, p.second);
        }

        return furthest_dist;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // The center of the graph is the node(s) with the lowest eccentricity (maximum distance) with all other nodes.
        // A tree has either 1 or 2 center nodes.
        // The center nodes are the middle nodes in the diameter of a graph. 
        // On a tree, we can find the diameter by performing a BFS from `x` to some 
        // farthest away node `y`, then performing BFS from `y` to the farthest away node from it `z`. 
        // This gives (y, z) as the diameter. 

        // Find the diameter of both graphs. 
        // The solution is half the diameter of graph1 + half the diameter of graph2 + 1. 

        int edges1_dia = diameter(edges1);
        int edges2_dia = diameter(edges2);
        int edges1_center_edges2_center = ceil(static_cast<double>(edges1_dia) / 2) + ceil(static_cast<double>(edges2_dia) / 2) + 1;

        return max({edges1_center_edges2_center, edges1_dia, edges2_dia});
    }
};