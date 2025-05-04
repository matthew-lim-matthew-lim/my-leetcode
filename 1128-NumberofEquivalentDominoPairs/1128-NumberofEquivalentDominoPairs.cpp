// Last updated: 5/4/2025, 12:33:05 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        multiset<vector<int>> dominoeSet;

        for (vector<int> &dominoe : dominoes) {
            sort(dominoe.begin(), dominoe.end());

            if (dominoeSet.contains(dominoe)) {
                res += dominoeSet.count(dominoe);
            }
            dominoeSet.emplace(dominoe);
        }

        return res;
    }
};