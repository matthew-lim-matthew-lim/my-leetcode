class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Djikstra's algorithm
        vector<unordered_map<int, int>> adjList(n + 1, unordered_map<int, int>());
        for (vector<int>& time : times) {
            int src = time[0];
            int dst = time[1];
            int w = time[2];
            adjList[src][dst] = w;
        }

        // Use Djikstras to find the shortest distance to every node
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // min pq { dist, vertex }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({ 0, k });

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > dist[u]) continue;

            for (pair<int, int> edge : adjList[u]) {
                int w = edge.second;
                int v = edge.first;
                cout << u << " " << v << " " << w << endl;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({ dist[v], v });
                }
            }
        }

        // Get the max distance to reach all the nodes.
        int res = -1;
        for (int i = 1; i < n + 1; i++) {
            cout << dist[i] << endl;
            res = max(res, dist[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};