// Last updated: 5/17/2025, 2:23:12 PM
class Solution {
public:
/* 
Bubble sort.
 */

    void sortColors(vector<int>& nums) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    swap(nums[i - 1], nums[i]);
                    sorted = false;
                }
            }
        }

        return;
    }
};