// Last updated: 4/9/2025, 1:34:10 PM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(n^2) dp.
        int n = nums.size();
        vector<int> dp(n, 1);

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};