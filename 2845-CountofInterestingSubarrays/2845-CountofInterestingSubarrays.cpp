// Last updated: 4/25/2025, 1:45:56 PM
class Solution {
public:
// Prefix sums
// At each index, record the culmulative count (prefix sum). 

// Isn't it O(n^2)-able with a loop?
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        
        int prev = 0;
        unordered_map<int, long long> validCount;
        validCount[0] = 1;

        long long res = 0;
        for (int i = 1; i < n + 1; i++) {
            int curr = prev + (nums[i - 1] % modulo == k ? 1 : 0);
            res += validCount[(curr + modulo - k) % modulo];
            validCount[curr % modulo]++;
            prev = curr;
        }

        // For each index, check if there are results:
        // count[i] - k * value == 0.

        return res;
    }
};