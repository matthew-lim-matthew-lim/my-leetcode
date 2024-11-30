class Solution {
public:
    void hierholzer(int start, unordered_map<int, vector<int>>& adjList, vector<int>& circuit) {
        stack<int> currPath;
        currPath.push(start);
        int currV = start;

        while (!currPath.empty()) {
            if (!adjList[currV].empty()) {
                currPath.push(currV);
                int nextV = adjList[currV].back();
                adjList[currV].pop_back();

                currV = nextV;
            } else {
                circuit.push_back(currV);
                currV = currPath.top();
                currPath.pop();
            }
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Hierholzer's algorithm

        // Keep track of indegree and outdegree to find the suitable start vertex
        unordered_map<int, int> degree;

        // Construct the adjacency list
        unordered_map<int, vector<int>> adjList;
        for (vector<int>& pair : pairs) {
            adjList[pair[0]].push_back(pair[1]);
            degree[pair[0]]++;
            degree[pair[1]]--;
        }

        // Find the start vertex
        int startVertex = pairs[0][0];
        for (pair<int, int> node_degree : degree) {
            if (node_degree.second == 1) {
                startVertex = node_degree.first;
                break;
            }
        }

        vector<int> circuit;
        hierholzer(startVertex, adjList, circuit);

        // Construct the solution to be in the format we want.
        vector<vector<int>> res;

        vector<int> edge_entry;
        for (int i = circuit.size() - 1; i >= 0; i--) {
            edge_entry.push_back(circuit[i]);
            if (edge_entry.size() == 2) {
                res.push_back(edge_entry);
                edge_entry.clear();
                edge_entry.push_back(circuit[i]);
            }
        }

        return res;
    }
};