class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Since we have to use every edge exactly once, this is a Eular path problem.
        // We use Hierholzer's algorithm
        unordered_map<string, multiset<string>> adjList;
        for (vector<string> ticket : tickets) {
            adjList[ticket[0]].insert(ticket[1]);
        }

        // DFS with Hierholzer's algorithm
        vector<string> res;

        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty()) {
            string curr = stk.top();
            stk.pop();

            if (adjList[curr].empty()) {
                res.push_back(curr);
            } else {
                stk.push(curr);
                // Since multiset, need to remove using iterator. 
                // Otherwise we would remove all entries with that value.
                auto it = adjList[curr].begin();
                string next = *it;
                adjList[curr].erase(it);
                stk.push(next);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};