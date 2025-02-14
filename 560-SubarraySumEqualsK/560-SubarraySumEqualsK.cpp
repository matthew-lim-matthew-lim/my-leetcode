class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Sliding window
        int lptr = 0;
        int n = nums.size();
        int res = 0;


        // Prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        // Count res
        for (int i = 0; i < n + 1; i++) {
            for (int j = i + 1; j < n + 1; j++) {
                if (prefix[j] - prefix[i] == k) {
                    res++;
                }
            }
        }

        return res;
    }
};