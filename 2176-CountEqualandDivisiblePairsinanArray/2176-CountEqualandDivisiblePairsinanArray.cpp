// Last updated: 4/17/2025, 10:46:00 PM
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        // Brute force
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && ((i * j) / k) * k == (i * j)) {
                    res++;
                }
            }
        }

        return res;
    }
};