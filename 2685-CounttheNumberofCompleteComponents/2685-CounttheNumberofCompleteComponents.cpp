// Last updated: 3/22/2025, 2:01:50 PM
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (vector<int> &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
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
                if (adjList[componentNodes[j]].size() != componentNodes.size() - 1) {
                    valid = false;
                    break;
                }
            }
            if (valid == true) {
                res++;
            }
        }

        return res;
    }
};