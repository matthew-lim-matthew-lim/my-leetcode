class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // BFS with a priority queue. The PQ will have { time, node }. 
        // n courses.

        // Keep a vector that stores how many required to activate a node
        vector<int> activate(n + 1, 0);

        vector<vector<int>> adjList(n + 1, vector<int>());
        for (int i = 0; i < relations.size(); i++) {
            adjList[relations[i][0]].push_back(relations[i][1]);
            activate[relations[i][1]]++;
        }

        // BFS with PQ.
        // Pair is { time, node }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 1; i < activate.size(); i++) {
            if (activate[i] == 0) {
                pq.push({ time[i - 1], i });
            }
        }

        int longestTime = 0;

        while (!pq.empty()) {
            // Whatever curr is, its the node that is 'done'. 
            pair<int, int> curr = pq.top();
            pq.pop();

            int currTime = curr.first;
            int currNode = curr.second;
            // cout << currNode << " at time: " << currTime << endl;

            longestTime = max(longestTime, currTime);

            for (int neigh : adjList[currNode]) {
                activate[neigh]--;
                if (activate[neigh] == 0) {
                    // If the node isn't waiting on any more activations, we can start to activate it. 
                    pq.push({ currTime + time[neigh - 1], neigh });
                }
            }
        }

        return longestTime;
    }
};