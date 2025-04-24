// Last updated: 4/24/2025, 7:32:17 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        // Each subarray contains all the elements. 
        // Sliding window?
        int reqChars = unordered_set<int>(nums.begin(), nums.end()).size();

        unordered_map<int, int> charMap;

        int res = 0;

        // We need to find the minimum subarrays that are complete.
        // Then, we count the extensions of that subarray leftwards and rightwards. 
        // Like (left + 1) * (n - right)
        int l = 0;

        for (int r = 0; r < n; r++) {
            charMap[nums[r]]++;
            while (charMap.size() == reqChars) {
                charMap[nums[l]]--;
                if (charMap[nums[l]] == 0) {
                    charMap.erase(nums[l]);
                }

                l++;
            }

            res += l; 
        }

        return res;
    }
};