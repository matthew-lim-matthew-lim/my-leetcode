// Last updated: 4/20/2025, 12:41:03 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> rabbitMap;
        for (int rab : answers) {
            if (!rabbitMap.contains(rab)) {
                res += 1 + rab;
                rabbitMap[rab] = 0;
            } else {
                rabbitMap[rab]++;
            }

            if (rabbitMap[rab] == rab) {
                rabbitMap.erase(rab);
            }
        }

        return res;
    }
};