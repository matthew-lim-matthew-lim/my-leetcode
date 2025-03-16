class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // All the vertices that have no incoming edges.
        vector<int> incomingEdges(n, 0);
        for (vector<int> &edge : edges) {
            incomingEdges[edge[1]]++;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (incomingEdges[i] == 0) {
                res.push_back(i);
            }
        }

        return res;
    }
};