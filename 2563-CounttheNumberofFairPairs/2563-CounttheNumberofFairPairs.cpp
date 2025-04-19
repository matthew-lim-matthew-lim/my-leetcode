// Last updated: 4/19/2025, 1:48:07 PM
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // For each index, find the indicies of lower_bound and upper_bound numbers that make a valid pair. 
        sort(nums.begin(), nums.end());

        long long res = 0;

        // For each index use upper_bound() and lower_bound() to get the bounds of indexes, the numbers within which make valid pairs.
        // This means O(n log n) since we run binary search 2 times for each value.
        for (long long i = 0; i < nums.size(); i++) {
            // Find the lowest number that would work with nums[i]
            long long low = lower - nums[i]; 
            // Find the larger number that would work with nums[i]
            long long high = upper - nums[i];

            long long low_index = lower_bound(nums.begin() + i, nums.end(), low) - nums.begin();

            long long high_index = upper_bound(nums.begin() + i, nums.end(), high) - nums.begin();

            res += high_index - low_index;

            // Exclude self-counting
            if (nums[i] + nums[i] <= upper && nums[i] + nums[i] >= lower) {
                res--;
            }
        }

        return res;
    }
};