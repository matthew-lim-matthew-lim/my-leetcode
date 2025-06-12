// Last updated: 6/12/2025, 11:33:18 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i - 1]));
        }

        return max(maxDiff, abs(nums[nums.size() - 1] - nums[0]));
    }
};