// Last updated: 9/18/2025, 12:18:37 AM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        if (n > 1) dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(max(dp[i], dp[i - 1]), dp[i - 2] + nums[i]);
        }

        return max(dp[n - 1], n > 1 ? dp[n - 2] : 0);
    }
};