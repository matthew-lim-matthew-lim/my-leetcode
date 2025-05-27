// Last updated: 5/27/2025, 10:21:29 PM
class Solution {
public:
/* 
Sort it.
 */

    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        return max(nums[0] * nums[1] * nums[n-1], nums[n-3] * nums[n-2] * nums[n-1]);
    }
};