// Last updated: 4/25/2025, 1:44:03 PM
class Solution {
public:
// Prefix sums
// At each index, record the culmulative count (prefix sum). 

// Isn't it O(n^2)-able with a loop?
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        
        vector<int> count(n + 1);
        unordered_map<int, long long> validCount;
        validCount[0] = 1;

        long long res = 0;
        for (int i = 1; i < n + 1; i++) {
            count[i] = count[i - 1] + (nums[i - 1] % modulo == k ? 1 : 0);
            res += validCount[(count[i] + modulo - k) % modulo];
            validCount[count[i] % modulo]++;
        }

        // For each index, check if there are results:
        // count[i] - k * value == 0.

        return res;
    }
};