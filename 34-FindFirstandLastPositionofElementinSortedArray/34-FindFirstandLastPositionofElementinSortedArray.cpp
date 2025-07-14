// Last updated: 7/15/2025, 1:21:37 AM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // We can use std::upper_bound()
        auto rPtr = upper_bound(nums.begin(), nums.end(), target);
        auto lPtr = upper_bound(nums.begin(), nums.end(), target - 1);

        if (rPtr == nums.begin()) {
            return { -1, -1 };
        }

        rPtr--;
        if (*rPtr != target) {
            cout << "hello" << endl;
            return { -1, -1 };
        }

        return { (int)(lPtr - nums.begin()), (int)(rPtr - nums.begin()) };
    }
};