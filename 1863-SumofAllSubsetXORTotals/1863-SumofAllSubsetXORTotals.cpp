// Last updated: 4/5/2025, 2:04:05 PM
class Solution {
public:
// nums.length <= 12, so brute force?
// Use backtracking
    void backtrack(int &currVal, int currIndex, vector<int>& nums, int currXor) {
        currVal += currXor;

        for (int i = currIndex; i < nums.size(); i++) {
            int newXor = currXor ^ nums[i];

            backtrack(currVal, i + 1, nums, newXor);
        }
    }

    int subsetXORSum(vector<int>& nums) {
        int currVal = 0;

        backtrack(currVal, 0, nums, 0);
        
        return currVal;
    }
};