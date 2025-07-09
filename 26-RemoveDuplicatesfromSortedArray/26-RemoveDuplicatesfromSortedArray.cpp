// Last updated: 7/9/2025, 10:18:36 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int prevUnique = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[prevUnique]) {
                prevUnique++;
                nums[prevUnique] = nums[i];
            }
        }

        return prevUnique + 1;
    }
};