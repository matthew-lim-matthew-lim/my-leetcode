// Last updated: 4/16/2025, 1:42:33 PM
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // For each l, find the minimum value of r such that the subarray is not good. 
        // All the remaining subarrays are therefore valid.
        // Use a hashmap to keep track of the number of occurences of each number.
        // Use currK to keep track of the current number of pairs.

        // Preprocess. Count number of pairs at each index. 
        // Hence, if k = 4, and pairCount[l] = 2, then we need to find 'r' for pairCount[r] = 4, which we
        // can do in O(log n) using binary search.

        long long res = 0;

        unordered_map<int, int> numCount;
        int currK = 0;

        int n = nums.size();

        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && currK < k) {
                currK += numCount[nums[r]];
                numCount[nums[r]]++; 
                r++;   
            }

            if (currK >= k) {
                res += (n - r + 1);
            }

            numCount[nums[l]]--;
            currK -= numCount[nums[l]];
        }

        return res;
    }
};