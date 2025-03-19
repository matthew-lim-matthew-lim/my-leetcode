class Solution {
public:
    bool dfs(vector<vector<int>> &adjList, int curr, vector<bool> &recursiveStack, vector<bool> &visited) {
        // cout << curr << endl;
        visited[curr] = true;
        recursiveStack[curr] = true;
        for (int neigh : adjList[curr]) {
            if (!visited[neigh]) {
                if (!dfs(adjList, neigh, recursiveStack, visited)) {
                    return false;
                }
            } else if (recursiveStack[neigh]) {  // Found a back edge (cycle)
                return false;
            }
        }

        recursiveStack[curr] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Cycle detection, use DFS
        vector<vector<int>> adjList(numCourses, vector<int>());


        for (vector<int> &edge : prerequisites) {
            if (edge[0] == edge[1]) {
                return false;
            }
            // Reverse the edges
            adjList[edge[1]].push_back(edge[0]);
            // We will start at the node that was dst, so leave that one as a valid start node. 
        }

        // Need to use DFS bruh.

        vector<bool> visited(numCourses, false);
        vector<bool> recursiveStack(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(adjList, i, recursiveStack, visited)) {
                    return false;
                }
            }
        }


        return true;
    }
};