class Solution {
public:
    int rob_house_helper(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> dp(nums.size(), 0);

        if (nums.size() >= 1) dp[0] = nums[0];
        if (nums.size() >= 2) dp[1] = max(nums[1], nums[0]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }

    int rob(vector<int>& nums) {
        // Calculate the max returns when 0 is taken
        vector<int> nums_copy;
        for (int i = 0; i < nums.size(); i++) {
            // Exclude the first number, and the numbers adjacent to it.
            if (i == 0 || i == 1 || i == nums.size() - 1) {
                continue;
            }
            nums_copy.push_back(nums[i]);
        }
        int yes_took_0 = nums[0] + rob_house_helper(nums_copy);

        // Calculate the max returns when 0 is not taken
        nums_copy.clear();
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                continue;
            }
            nums_copy.push_back(nums[i]);
        }
        int no_took_0 = rob_house_helper(nums_copy);

        return max(yes_took_0, no_took_0);
    }
};