// Last updated: 4/25/2025, 1:54:46 PM
class Solution {
public:
// Prefix sum
// Use a map to keep track of the number of sums with value `k - currSum`
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int prev = 0;
        unordered_map<int, int> countMap;
        countMap[0] = 1;
        for (int i = 1; i < n + 1; i++) {
            int curr = prev + nums[i - 1];
            res += countMap[curr - k];
            countMap[curr]++;
            prev = curr;
        }

        return res;
    }
};