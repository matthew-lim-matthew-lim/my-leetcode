class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // The graph is a DAG.
        // The main restriction is the number of queries is up to 10^4. The number of node is at max 100.
        // For each query [ u, j ], check if you can reach j from u. 

        vector<vector<int>> adjList(numCourses, vector<int>());
        for (vector<int>& prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }

        vector<unordered_set<int>> amortReqs(numCourses, unordered_set<int>());
        for (int node = 0; node < numCourses; node++) {
            // BFS from each node, adding every node that gets visited into amortReqs.
            queue<int> q;
            q.push(node);
            amortReqs[node].insert(node);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neigh : adjList[curr]) {
                    if (amortReqs[node].contains(neigh)) continue;
                    amortReqs[node].insert(neigh);
                    q.push(neigh);
                }
            }
        }

        vector<bool> res(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            res[i] = amortReqs[queries[i][0]].contains(queries[i][1]);
        }

        return res;
    }
};