// Last updated: 4/25/2025, 4:54:33 PM
class Solution {
public:
// Keep track of the furthest we can jump.
// If any index is within the range we can jump, consider jumping from there.
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (reach >= i) {
                reach = max(reach, i + nums[i]);
            }
        }

        return reach >= n - 1;
    }
};