class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Prefix sum, and then find the largest and smallest values. 
        int prefix = 0;
        int minVal = 0;
        int maxVal = 0;

        for (int num : nums) {
            prefix += num;
            minVal = min(minVal, prefix);
            maxVal = max(maxVal, prefix);
        }

        return max(abs(minVal - maxVal), maxVal - minVal);
    }
};