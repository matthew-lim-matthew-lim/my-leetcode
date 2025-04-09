// Last updated: 4/9/2025, 2:44:25 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // To pass TLE, maybe need to keep track of smallest positive val, and largest negative val (values closest to 0).
        // If number positive, use the smallest > 0. -> We don't actually need this. Because its positive, dont need to change the sign.
        // If number negative, use the largest < 0.
        // This should make it O(n), if I use an unordered_set to track zeros

        // DP
        // Prefix sum tyshi 
        // In the prefix sum, if there is a 0, treat the next value as a 1. 
        // But keep track of the location of the 0s. 
        int n = nums.size();
        vector<int> prefixProd(n, 1);
        unordered_set<int> zeroIndex;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroIndex.insert(i);
                prefixProd[i] = 1;
                continue;
            }
            prefixProd[i] = nums[i];
            if (i > 0) {
                prefixProd[i] = prefixProd[i - 1] * nums[i];
            }
        }

        // O(n)
        int res = nums.front();

        // Now, go through the potential subarrays.
        int largestBelowZero = INT_MIN;
        // If we encounter a zero, then reset the values.

        // i is the last number in the subarray
        bool encounteredZero = false;
        for (int i = 0; i < n; i++) {
            res = max(res, nums[i]);

            if (zeroIndex.contains(i)) {
                largestBelowZero = INT_MIN;
                encounteredZero = true;
                continue;
            }

            if (!encounteredZero) {
                res = max(res, prefixProd[i]);
            }

            if (prefixProd[i] > 0) {
                res = max(res, prefixProd[i]);
            }
            if (prefixProd[i] < 0) {
                if (largestBelowZero != INT_MIN) res = max(res, prefixProd[i] / largestBelowZero);
                largestBelowZero = max(largestBelowZero, prefixProd[i]);
            }
        }

        return res;
    }
};