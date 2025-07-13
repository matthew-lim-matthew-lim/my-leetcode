// Last updated: 7/13/2025, 2:50:09 PM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p_ptr = 0;
        int t_ptr = 0;

        int matchedCount = 0;

        while (p_ptr < n) {
            while (t_ptr < m && players[p_ptr] > trainers[t_ptr]) {
                t_ptr++;
            }
            if (t_ptr == m) {
                break;
            }
            matchedCount++;
            p_ptr++;
            t_ptr++;
        }

        return matchedCount;
    }
};