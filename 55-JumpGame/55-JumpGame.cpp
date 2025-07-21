// Last updated: 7/21/2025, 9:21:56 PM
/* 
Go from back to front and instead keep track of how for we can reach.
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int end = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] + i >= end) {
                end = i;
            }
        }

        return end == 0;
    }
};