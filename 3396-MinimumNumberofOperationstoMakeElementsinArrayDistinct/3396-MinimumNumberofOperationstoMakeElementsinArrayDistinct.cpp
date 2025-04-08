// Last updated: 4/8/2025, 11:14:37 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // Go from the back of the array and count the max subarray length
        // such that all the elements in the array are distinct. 
        int max_size = 0;
        unordered_set<int> u_set;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (u_set.contains(nums[i])) {
                break;
            }
            max_size++;
            u_set.insert(nums[i]);
        }

        // Now, can calculate the number of queries required.
        return ceil((nums.size() - max_size) / static_cast<double>(3));
    }
};