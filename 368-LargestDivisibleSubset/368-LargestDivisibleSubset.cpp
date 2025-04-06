// Last updated: 4/6/2025, 12:43:01 PM
class Solution {
public:
    // DP?
    // Sort all the numbers. O(n log n).
    // For each value, find the last value that is a factor, and add the count for that number. O(n^2).
    // Keep track of the number with the largest factor count.  
    // At the end, sweep back to the front, adding all the factors of the number with the largest 
    // factor count. O(n). 

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<int> factorCount(n, 1);
        vector<int> prevFactorIndex(n, -1);
        int highestFactorCount = 1;
        int factorIndex = 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            // For each value, search backwards to find the biggest factor of this number, 
            // and add the factor count to this num.

            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (factorCount[j] + 1 > factorCount[i]) {
                        factorCount[i] = factorCount[j] + 1;
                        prevFactorIndex[i] = j;
                    }
                }
                if (factorCount[i] > highestFactorCount) {
                    highestFactorCount = factorCount[i];
                    factorIndex = i;
                }
            }
        }

        // Now, sweep back to the front, adding all the factors of the number with the largest factor count.
        vector<int> res;
        
        while (factorIndex != -1) {
            res.push_back(nums[factorIndex]);

            factorIndex = prevFactorIndex[factorIndex];
        }

        return res;
    }
};