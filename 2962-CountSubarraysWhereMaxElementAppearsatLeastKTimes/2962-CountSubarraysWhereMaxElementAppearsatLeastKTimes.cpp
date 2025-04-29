// Last updated: 4/29/2025, 11:33:30 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());

        int count = 0;

        long long res = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] == maxElem) {
                count++;
            }
            while (l < n && count >= k) {
                if (nums[l] == maxElem) {
                    count--;
                }
                l++;
            }
            res += l;
        }

        return res;
    }
};