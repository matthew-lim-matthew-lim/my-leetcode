// Last updated: 5/19/2025, 2:03:12 PM
class Solution {
public:
/*
Use a set.
Super easy!
 */

    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }

        unordered_set<int> uSet(nums.begin(), nums.end());
        if (uSet.size() == 1) {
            return "equilateral";
        } 

        if (uSet.size() == 2) {
            return "isosceles";
        }

        return "scalene";
    }
};