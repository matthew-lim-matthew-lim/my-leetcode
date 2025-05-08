// Last updated: 5/8/2025, 1:30:21 PM
class Solution {
public:
    struct Coords {
        int y;
        int x;

        bool operator==(const Coords &other) const {
            return y == other.y && x == other.x;
        }
    };

    struct QueueEntry : Coords {
        int time;
        bool extraSecond;
    };

    struct CompareTime {
        bool operator()(const QueueEntry& a, const QueueEntry& b) const {
            return a.time > b.time;
        }
    };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        // BFS
        // Keep track of current time. Use a PQ with time and coordinates.
        priority_queue<QueueEntry, vector<QueueEntry>, CompareTime> pq;

        pq.push(QueueEntry{0, 0, 0, false});

        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> best(n, vector<int>(m, INT_MAX));
        best[0][0] = 0;

        while (!pq.empty()) {
            QueueEntry curr = pq.top();
            pq.pop();

            if (curr.time != best[curr.y][curr.x]) {
                continue;
            }
            if (curr.y == n - 1 && curr.x == m - 1) {
                return curr.time;
            }

            // up, down, left, right
            auto tryMove = [&](int ny, int nx) {
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) return;
                int nt = max(curr.time + 1 + curr.extraSecond, moveTime[ny][nx] + 1 + curr.extraSecond); 
                if (nt < best[ny][nx]) {
                    best[ny][nx] = nt;
                    pq.push({ny, nx, nt, !curr.extraSecond});
                }
            };

            tryMove(curr.y + 1, curr.x);
            tryMove(curr.y - 1, curr.x);
            tryMove(curr.y, curr.x + 1);
            tryMove(curr.y, curr.x - 1);
        }

        return 0;
    }
};