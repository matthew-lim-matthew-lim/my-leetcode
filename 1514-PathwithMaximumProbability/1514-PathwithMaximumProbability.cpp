// Last updated: 4/25/2026, 8:30:39 PM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> max_p(n, 0.0);
        max_p[start_node] = 1.0;

        for (int i = 0; i < n - 1; i++) {
            bool changed = false;
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if (max_p[u] * prob > max_p[v]) {
                    max_p[v] = max_p[u] * prob;
                    changed = true;
                }
                if (max_p[v] * prob > max_p[u]) {
                    max_p[u] = max_p[v] * prob;
                    changed = true;
                }
            }
            if (!changed) break;
        }

        return max_p[end_node];
    }
};