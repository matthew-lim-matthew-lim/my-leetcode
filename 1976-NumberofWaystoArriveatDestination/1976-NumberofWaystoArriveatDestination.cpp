// Last updated: 3/24/2025, 1:44:41 AM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Modified djikstra's?

        vector<vector<pair<int, int>>> adjList(n);
        for (vector<int>& road : roads) {
            adjList[road[0]].push_back({ road[1], road[2] });
            adjList[road[1]].push_back({ road[0], road[2] });
        }

        vector<pair<long long, long long>> dist(n, pair<long long, long long>(LLONG_MAX, 0));

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;

        dist[0].first = 0;
        dist[0].second = 1;
        pq.push({ 0, 0 });

        while (!pq.empty()) {
            pair<long long, long long> curr = pq.top();
            pq.pop();

            long long u = curr.second;
            long long d = curr.first;

            long long numWaysU = dist[u].second;

            // Process edges from u
            for (pair<int, int> neigh : adjList[u]) {
                int v = neigh.first;
                int weight = neigh.second;
                // cout << "node: " << v << " from: " << u << endl;
                // cout << d + weight << " " << dist[v].first << endl;
                if (d + weight == dist[v].first) {
                    dist[v].second += numWaysU;
                    dist[v].second %= 1000000007;
                }
                if (d + weight < dist[v].first) {
                    // cout << "new way" << endl;
                    dist[v] = { d + weight, numWaysU };
                    pq.push({ dist[v].first, v });
                }
                // cout << dist[v].first << " : " << dist[v].second << endl;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << i << ": " << dist[i].second << endl;
        // }

        return dist[n - 1].second % 1000000007;
    }
};