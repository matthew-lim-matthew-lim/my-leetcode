// Last updated: 4/9/2025, 2:14:19 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Keep track of the smallest prefixSum up to this point
        int smallest = 0;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, prefixSum[i] - smallest);
            smallest = min(smallest, prefixSum[i]);
        }

        return res;
    }
};