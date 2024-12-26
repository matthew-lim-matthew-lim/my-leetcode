class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int nums_sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums_sum / 2 != nums_sum / 2.0) {
            return false;
        }

        // Try and see if there exists `chosen` such that sum(chosen) = sum(all) / 2.0;
        // This is like selecting a subset which sums to K.
        vector<unordered_set<int>> dp(nums.size(), unordered_set<int>({0, nums[0]}));
        for (int i = 1; i < nums.size(); i++) {
            for (int val : dp[i - 1]) {
                dp[i].insert(val);
                dp[i].insert(val + nums[i]);
            }
        }

        return dp[nums.size() - 1].contains(nums_sum / 2.0);
    }
};