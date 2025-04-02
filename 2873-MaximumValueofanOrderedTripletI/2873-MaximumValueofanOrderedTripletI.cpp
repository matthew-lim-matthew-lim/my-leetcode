// Last updated: 4/2/2025, 2:11:56 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // O(n^3) is okay.
        int n = nums.size();
        long long maxVal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    maxVal = max(maxVal, (long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }

        return maxVal;
    }
};