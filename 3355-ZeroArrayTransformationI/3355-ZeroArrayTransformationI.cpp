// Last updated: 5/20/2025, 11:07:46 AM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // Need to use a difference array to meet time complexity requirements
        vector<int> difference_array(nums.size() + 1, 0);

        for (vector<int> query : queries) {
            difference_array[query[0]]--;
            difference_array[query[1] + 1]++;
        }

        // Compute prefix sum of difference array
        for (int i = 1; i < difference_array.size(); i++) {
            difference_array[i] += difference_array[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + difference_array[i] > 0) {
                return false;
            }
        } 

        return true;
    }
};