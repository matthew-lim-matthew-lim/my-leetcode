class Solution {
public:
    bool verify(vector<int>& nums, int capacity, int k) {
        int n = nums.size();
        // Just need to check if there are k non-adjacent numbers (<=) capacity. 
        // DP?
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int prev1 = i - 1 >= 0 ? dp[i - 1] : 0;
            int prev2 = i - 2 >= 0 ? dp[i - 2] : 0;
            dp[i] = max(prev1, prev2 + (nums[i] <= capacity));
        }

        return dp[n - 1] >= k;
    }

    // Find the smallest X such that f(X) is true;
    int binarysearch(vector<int> &nums, int k) {
        int lo = 0;
        int hi = *max_element(nums.begin(), nums.end());
        int bestSoFar = -1;
        // Range [lo, hi];
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (verify(nums, mid, k)) {
                bestSoFar = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return bestSoFar;
    }

    int minCapability(vector<int>& nums, int k) {
        // Binary search for minimum capacity.
        // Verify by checking for if we can rob at least k with a specific capacity.

        return binarysearch(nums, k);
    }
};