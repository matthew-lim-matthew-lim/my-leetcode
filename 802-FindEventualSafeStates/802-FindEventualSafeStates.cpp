class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Terminal node
        unordered_set<int> safe;
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() == 0) {
                safe.insert(i);
            }
        }

        // Safe node
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < graph.size(); i++) {
                if (!safe.contains(i)) {
                    bool safe_check = true;
                    for (int j = 0; j < graph[i].size(); j++) {
                        if (!safe.contains(graph[i][j])) {
                            safe_check = false;
                        }
                    }
                    if (safe_check) {
                        safe.insert(i);
                        changed = true;
                    }
                }
            }
        }

        vector<int> res(safe.begin(), safe.end());
        sort(res.begin(), res.end());

        return res;
    }
};