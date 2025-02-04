class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];
                res = max(res, currSum);
            } else {
                currSum = nums[i];
            }
        }

        return res;
    }
};