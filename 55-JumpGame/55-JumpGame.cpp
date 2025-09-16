// Last updated: 9/16/2025, 1:57:01 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currEnd = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i + nums[i] >= currEnd) {
                currEnd = i;
            }
        }

        return currEnd == 0;
    }
};