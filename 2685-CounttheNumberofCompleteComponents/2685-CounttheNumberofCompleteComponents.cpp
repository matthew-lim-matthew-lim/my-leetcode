// Last updated: 3/22/2025, 1:59:26 PM
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjList(n);
        for (vector<int> &edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }

        int res = 0;

        // Explore every node, building a set of components. 
        // Then, check that every node in the set can visit every other node. 
        unordered_set<int> visited; 

        for (int i = 0; i < n; i++) {
            if (visited.contains(i)) {
                continue;
            }
            vector<int> componentNodes; 

            // BFS from i.
            queue<int> q;

            q.push(i);
            visited.insert(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                componentNodes.push_back(curr);

                for (int neigh : adjList[curr]) {
                    if (visited.contains(neigh)) {
                        continue;
                    }

                    visited.insert(neigh);
                    q.push(neigh);
                }
            }

            // We visited all the nodes in the component. Now, see if every node
            // can visit every other node. 
            bool valid = true;
            for (int j = 0; j < componentNodes.size(); j++) {
                for (int k = 0; k < componentNodes.size(); k++) {
                    if (j == k) {
                        continue;
                    }
                    if (!adjList[componentNodes[j]].contains(componentNodes[k])) {
                        valid = false;
                    }
                }
            }
            if (valid == true) {
                res++;
            }
        }

        return res;
    }
};