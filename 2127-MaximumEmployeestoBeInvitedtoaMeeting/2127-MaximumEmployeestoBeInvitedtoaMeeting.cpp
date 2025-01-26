class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // Build a reverse graph so that we can see which nodes allow more nodes to be explored.
        // We use it for the BFS for finding the acyclic chains.
        // For the actual cyclefinding, we use the main graph, which is convenient because each node has exactly 1 outgoing edge. This
        // makes it easy to track the length of the cycle (which we do using visitedPersons, which we would only set once for each node).
        vector<vector<int>> reversedGraph(n);
        for (int person = 0; person < n; ++person) {
            reversedGraph[favorite[person]].push_back(person);
        }

        // Helper function for BFS. 
        // This is used for finding the acyclic chains which attach to 2-node cycles. 
        auto bfs = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
            queue<pair<int, int>> q;
            q.push({startNode, 0});
            int maxDistance = 0;
            while (!q.empty()) {
                auto [currentNode, currentDistance] = q.front();
                q.pop();
                for (int neighbor : reversedGraph[currentNode]) {
                    if (visitedNodes.contains(neighbor)) continue;
                    visitedNodes.insert(neighbor);
                    q.push({neighbor, currentDistance + 1});
                    maxDistance = max(maxDistance, currentDistance + 1);
                }
            }
            return maxDistance;
        };

        int longestCycle = 0, twoCycleInvitations = 0;
        vector<bool> visited(n, false);

        // Find all cycles
        // Run cycle finding from each node in the graph. 
        // This is using the original graph, where each node only has 1 outgoing edge.
        for (int person = 0; person < n; ++person) {
            if (!visited[person]) {
                unordered_map<int, int> visitedPersons;
                int current = person;
                int distance = 0;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitedPersons[current] = distance++;
                    int nextPerson = favorite[current];
                    if (visitedPersons.contains(nextPerson)) {  // Cycle detected
                        int cycleLength = distance - visitedPersons[nextPerson];
                        longestCycle = max(longestCycle, cycleLength);
                        if (cycleLength == 2) {
                            // If the cycle is length 2, then we can attach up to 2 acyclic chains, terminating at each
                            // end of the two-node cycle. 
                            unordered_set<int> visitedNodes = {current,
                                                               nextPerson};
                            twoCycleInvitations +=
                                2 + bfs(nextPerson, visitedNodes) +
                                bfs(current, visitedNodes);
                        }
                        break;
                    }
                    current = nextPerson;
                }
            }
        }

        return max(longestCycle, twoCycleInvitations);
    }
};