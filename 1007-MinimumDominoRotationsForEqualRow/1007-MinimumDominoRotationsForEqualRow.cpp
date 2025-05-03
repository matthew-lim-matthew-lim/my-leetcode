// Last updated: 5/3/2025, 1:11:07 PM
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Need 'n' of the same value.
        // Just count the number of each one accross both top and bottom. 
        vector<int> topCount(6,0);
        vector<int> bottomCount(6, 0);

        int n = tops.size();

        for (int i = 0; i < n; i++) {
            topCount[tops[i] - 1]++;
            if (tops[i] != bottoms[i]) {
                bottomCount[bottoms[i] - 1]++;
            }
        }

        int minRotations = INT_MAX;
        for (int i = 0; i < 6; i++) {
            // cout << topCount[i] + bottomCount[i] << endl;
            if (topCount[i] + bottomCount[i] == n) {
                minRotations = min(minRotations, min(topCount[i], bottomCount[i]));
            }
        }

        topCount.clear();
        bottomCount.clear();
        topCount.resize(6);
        bottomCount.resize(6);

        for (int i = 0; i < n; i++) {
            bottomCount[bottoms[i] - 1]++;
            if (tops[i] != bottoms[i]) {
                topCount[tops[i] - 1]++;
            }
        }

        for (int i = 0; i < 6; i++) {
            // cout << topCount[i] + bottomCount[i] << endl;
            if (topCount[i] + bottomCount[i] == n) {
                minRotations = min(minRotations, min(topCount[i], bottomCount[i]));
            }
        }

        return minRotations == INT_MAX ? -1 : minRotations;
    }
};