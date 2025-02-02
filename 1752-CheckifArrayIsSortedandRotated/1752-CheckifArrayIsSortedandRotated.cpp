class Solution {
public:
    bool check(vector<int>& nums) {
        // At most one increase in value.
        int increaseCount = 0;
        int prev = nums.front();
        if (nums[nums.size() - 1] > nums[0]) increaseCount++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) increaseCount++;
            if (increaseCount > 1) return false;
        }

        return true;
    }
};