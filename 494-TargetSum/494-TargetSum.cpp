class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int nums_sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums_sum < abs(target)) return 0;

        // Initialise it to all 0's.
        vector<vector<int>> dp(nums.size(), vector<int>(2 * nums_sum + 1, 0));

        dp[0][nums_sum - nums[0]] += 1;
        dp[0][nums_sum + nums[0]] += 1;

        // opt(i, j)
        // For each i, compute for entire j range.
        int curr_nums_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_nums_sum += nums[i];
            for (int j = -curr_nums_sum; j <= curr_nums_sum; j++) {
                int left = nums_sum + j - nums[i] < 0 ? 0 : dp[i - 1][nums_sum + j - nums[i]];
                int right = nums_sum + j + nums[i] >= 2 * nums_sum + 1 ? 0 : dp[i - 1][nums_sum + j + nums[i]];
                dp[i][nums_sum + j] = left + right;
            }
        }

        return dp[nums.size() - 1][nums_sum + target];
    }
};