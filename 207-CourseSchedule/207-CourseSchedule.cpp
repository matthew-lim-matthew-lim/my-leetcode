// Last updated: 7/10/2025, 12:38:26 PM
/* 
[a, b] means you need to take b first before a. 

Make a graph. Key is start (b) and is dest (a). 
While constructing, keep track of nodes that have no dependencies.

BFS traverse graph to see if you can visit all nodes. 
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> validStart;
        for (int i = 0; i < numCourses; i++) {
            validStart.insert(i);
        }

        unordered_map<int, unordered_set<int>> nodeToMyPrereqs;
        unordered_map<int, unordered_set<int>> nodeToNieghbours;

        // Construct graph
        for (const vector<int> &edge : prerequisites) {
            nodeToMyPrereqs[edge[0]].insert(edge[1]);
            nodeToNieghbours[edge[1]].insert(edge[0]);
            validStart.erase(edge[0]);
        }

        // Attempt traverse
        unordered_set<int> visited;
        queue<int> q;
        for (int val : validStart) {
            q.push(val);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited.insert(curr);

            for (int neigh : nodeToNieghbours[curr]) {
                nodeToMyPrereqs[neigh].erase(curr);

                if (!visited.contains(neigh) && nodeToMyPrereqs[neigh].empty()) {
                    q.push(neigh);
                }
            }
        }

        return visited.size() == numCourses;
    }
};