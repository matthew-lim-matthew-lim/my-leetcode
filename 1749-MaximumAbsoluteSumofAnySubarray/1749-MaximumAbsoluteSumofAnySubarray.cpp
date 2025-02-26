class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Prefix sum, and then find the largest and smallest values. 
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int maxVal = *max_element(prefix.begin(), prefix.end());
        int minVal = *min_element(prefix.begin(), prefix.end());

        return max(abs(minVal - maxVal), maxVal - minVal);
    }
};