class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    bool unite(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; 
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;  
            }
            return false;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // We can easily use union-find, and by placing edges iteratively, the last edge we put in is the edge to be removed.
        int n = edges.size();
        vector<int> rank(n + 1, 1);
        vector<int> parent(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            parent[i] = i;
        }

        for (vector<int> edge : edges) {
            if (unite(edge[0], edge[1], parent, rank) == true) return edge; 
        }

        return {};
    }
};