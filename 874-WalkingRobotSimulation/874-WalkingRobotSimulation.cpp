class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // { Y, X }
        vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        int direction = 0;
        pair<int, int> position = { 0, 0 };
        int res = 0;

        unordered_map<int, unordered_set<int>> oMap;
        for (vector<int>& o : obstacles) {
            oMap[o[1]].insert(o[0]);
        }

        // Process commands
        for (int c : commands) {
            if (c == -1) {
                direction++;
                if (direction == directions.size()) {
                    direction = 0;
                }
            } else if (c == -2) {
                direction--;
                if (direction < 0) {
                    direction = directions.size() - 1;
                }
            } else {
                for (int i = 0; i < c; i++) {
                    int newY = position.first + directions[direction].first;
                    int newX = position.second + directions[direction].second;
                    if (oMap[newY].contains(newX)) {
                        break;
                    }
                    position.first = newY;
                    position.second = newX;
                }
            }
            res = max(res, static_cast<int>(pow(position.first, 2) + pow(position.second, 2)));
        }

        return res;
    }
};