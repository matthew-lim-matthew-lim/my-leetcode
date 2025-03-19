class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Sliding window. 
        // Slide until l_ptr is at a `0`.
        // If l_ptr is at a `0`, but r_ptr >= n, 
        // then it is impossible. 
        int flipCount = 0;
        int n = nums.size();
        for (int l_ptr = 0; l_ptr < n; l_ptr++) {
            // r_ptr = l_ptr + 2;
            if (nums[l_ptr] == 1) {
                continue;
            } 
            if (l_ptr + 2 >= n) {
                return -1;
            }
            for (int i = l_ptr; i < l_ptr + 3; i++) {
                nums[i] = !nums[i];
            }
            flipCount++;
        }

        return flipCount;
    }
};