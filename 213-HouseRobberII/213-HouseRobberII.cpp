// Last updated: 4/9/2025, 1:10:33 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        // Break it into 2 cases
        int n = nums.size();
        if (n <= 2) {
            return *max_element(nums.begin(), nums.end());
        }
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = nums[0];
        dp[0][1] = max(nums[0], nums[1]);
        dp[1][0] = 0;
        dp[1][1] = nums[1];

        for (int i = 2; i < n - 1; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + nums[i]);
            dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + nums[i]);
        }
        dp[0][n - 1] = dp[0][n - 2];
        dp[1][n - 1] = max(dp[1][n - 2], dp[1][n - 3] + nums[n - 1]);

        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};