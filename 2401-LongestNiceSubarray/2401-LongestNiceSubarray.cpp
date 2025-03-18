class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // Sliding window keeping track of all the bits that were activated.
        // Use an OR to add the number to the tracker. 
        // Use an AND to check if we can add the newest number. 
        // Use an XOR to remove the number from l_ptr. 
        int longest = 0;
        int n = nums.size();
        int l_ptr = 0;
        uint32_t bitWindow = 0;
        for (int r_ptr = 0; r_ptr < n; r_ptr++) {
            // Move the l_ptr while there are overlapping bits. 
            while ((bitWindow & nums[r_ptr]) != 0) {
                bitWindow = (bitWindow ^ nums[l_ptr]);
                l_ptr++;
            }
            // Add the new bits to the tracker.
            if ((bitWindow & nums[r_ptr]) == 0) {
                bitWindow = bitWindow | nums[r_ptr];
            }

            longest = max(longest, r_ptr - l_ptr + 1);
        }

        return longest;
    }
};