// Last updated: 4/9/2025, 11:27:37 PM
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Just create a set with all nodes, and exclude nodes that don't have an incoming edge
        vector<bool> incoming(n, false);
        for (vector<int> &edge : edges) {
            incoming[edge[1]] = true;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (incoming[i] == false) {
                res.push_back(i);
            }
        }

        return res;
    }
};