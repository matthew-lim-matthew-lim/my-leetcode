class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negativeCount = 0;
        int positiveCount = 0;
        for (int v : nums) {
            if (v > 0) positiveCount++;
            if (v < 0) negativeCount++;
        }

        return max(positiveCount, negativeCount);
    }
};