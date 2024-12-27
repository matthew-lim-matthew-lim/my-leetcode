class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // DP
        int currLargest = values[0];
        int maxScore = 0;
        for (int i = 1; i < values.size(); i++) {
            currLargest--;
            maxScore = max(maxScore, currLargest + values[i]);
            currLargest = max(currLargest, values[i]);
        }

        return maxScore;
    }
};