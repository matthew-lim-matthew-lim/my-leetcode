// Last updated: 4/27/2025, 1:08:07 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int r = 2; r < n; r++) {
            res += (nums[r - 1] / 2.0) == (nums[r - 2] + nums[r]);
        }

        return res;
    }
};