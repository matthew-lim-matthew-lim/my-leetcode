class Solution {
public:
    struct UnionFind {
        vector<int> parent, rank;
        UnionFind(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int findSet(int u) {
            if (parent[u] != u) {
                parent[u] = findSet(parent[u]);
            }
            return parent[u];
        }
        
        void unionSet(int u, int v) {
            int ru = findSet(u);
            int rv = findSet(v);
            if (ru != rv) {
                // union by rank
                if (rank[ru] < rank[rv]) {
                    parent[ru] = rv;
                } else if (rank[ru] > rank[rv]) {
                    parent[rv] = ru;
                } else {
                    parent[rv] = ru;
                    rank[ru]++;
                }
            }
        }
        
        int count() {
            unordered_set<int> count;
            for (int i = 0; i < parent.size(); i++) {
                count.insert(findSet(i));
            }

            return count.size();
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind nodeGroups(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    nodeGroups.unionSet(i, j);
                }
            }
        }

        return n - nodeGroups.count();
    }
};