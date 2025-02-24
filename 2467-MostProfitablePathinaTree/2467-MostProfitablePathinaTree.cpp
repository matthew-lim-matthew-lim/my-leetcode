class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // Bob BFS to 0 (since we are using a tree). Track when Bob reaches each node in that optimal path. 
        // Alice BFS layer-by-layer, tracking the current step and running profit. 
        // If reached a node, check when Bob reached that node to determine how much Alice new profit is.

        // Make an adj list. 
        vector<vector<int>> adjList(edges.size() + 1, vector<int>());
        for (vector<int>& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // BFS for Bob to get to 0.
        vector<int> bobArrive(edges.size() + 1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({ bob, 0 });
        vector<pair<int, int>> prev(edges.size() + 1, { -1, 0 });
        prev[bob] = { 0, 0 };

        while (!q.empty()) {
            auto [ currNode, currLvl ] = q.front();
            q.pop();
            if (currNode == 0) {
                break;
            }
            for (int neigh : adjList[currNode]) {
                // cout << neigh << endl;
                if (prev[neigh].first == -1) {
                    q.push({ neigh, currLvl + 1 });
                    prev[neigh] = { currNode, currLvl + 1 };
                }
            }
        }

        int bobCurr = 0;
        bobArrive[bobCurr] = prev[bobCurr].second;
        while (bobCurr != bob) {
            bobCurr = prev[bobCurr].first;
            bobArrive[bobCurr] = prev[bobCurr].second;
        }

        // cout << "res:" << endl;

        // for (int i : bobArrive) {
        //     cout << i << endl;
        // }

        // cout << "qAlice:" << endl;

        // BFS for Alice to find the cheapest path
        queue<vector<int>> qAlice;
        vector<bool> visited(edges.size() + 1, false);
        visited[0] = true;
        // If Alice reaches a node after bob, it is free. If same time as bob, half price. Otherwise, full price. 
        qAlice.push({0, 0, amount[0]});
        set<int> res;
        while (!qAlice.empty()) {
            vector<int> frontVec = qAlice.front();
            int currNode = frontVec[0];
            int currLvl = frontVec[1];
            int currVal = frontVec[2];
            // cout << currNode << " " << currVal << endl;
            qAlice.pop();

            if (adjList[currNode].size() == 1 && visited[adjList[currNode][0]] == true) {
                res.insert(currVal);
            } 

            for (int neigh : adjList[currNode]) {
                // cout << neigh << endl;
                if (visited[neigh] == false) {
                    visited[neigh] = true;
                    // Determine if visited
                    int cost;
                    if (bobArrive[neigh] < currLvl + 1) {
                        cost = 0;
                    } else if (bobArrive[neigh] == currLvl + 1) {
                        cost = amount[neigh] / 2;
                    } else {
                        cost = amount[neigh];
                    }

                    qAlice.push({ neigh, currLvl + 1, currVal + cost });
                }
            }
        }

        return *res.rbegin();
    }
};