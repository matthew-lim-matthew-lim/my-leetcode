class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Sliding window
        int lPtr = 0;
        int zeroCount = 0;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }
            while (zeroCount > 1) {
                if (nums[lPtr] == 0) {
                    zeroCount--;
                }
                lPtr++;
            }
            res = max(res, i - lPtr + 1);
        }

        return res;
    }
};