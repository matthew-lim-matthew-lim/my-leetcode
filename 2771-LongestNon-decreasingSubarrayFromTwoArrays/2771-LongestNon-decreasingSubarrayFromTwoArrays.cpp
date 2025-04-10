// Last updated: 4/10/2025, 9:41:59 PM
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        // Just greedily pick the min(nums1[i], nums2[i]) for each i. 
        // Keep track of the longest one so far.
        int n = nums1.size();
        vector<vector<int>> dp(2, vector<int>(n, 1));

        int currVal = min(nums1[0], nums2[0]);

        int res = 1;
        
        // Make nums1 have all the smaller values
        for (int i = 0; i < n; i++) {
            if (nums1[i] > nums2[i]) {
                swap(nums1[i], nums2[i]);
            }
        }

        // dp[0] is if u picked from nums1
        // dp[1] is if u picked from nums2
        for (int i = 1; i < n; i++) {
            int LL = (nums1[i] >= nums1[i - 1]) ? dp[0][i - 1] + 1 : 1;
            int BR = (nums1[i] >= nums2[i - 1]) ? dp[1][i - 1] + 1 : 1;
            dp[0][i] = max(LL, BR);

            LL = (nums2[i] >= nums2[i - 1]) ? dp[1][i - 1] + 1 : 1;
            int TL = (nums2[i] >= nums1[i - 1]) ? dp[0][i - 1] + 1 : 1;
            dp[1][i] = max(LL, TL);

            res = max(res, dp[0][i]);
            res = max(res, dp[1][i]);
        }

        // Can't just do it greedily, since for one particular array, it might be better to pick the smallest, 
        // whereas for another array, it might be better to pick the largest. 
        // Maybe for dp[0] pick the smallest, and dp[1] pick the one bigger. 

        return res;
    }
};