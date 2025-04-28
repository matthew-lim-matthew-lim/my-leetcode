// Last updated: 4/28/2025, 12:25:17 PM
class Solution {
public:
    int binarySearch(vector<long long>& prefixSum, int l, long long k) {
        // We want to find the best (largest) `r`. 
        long long lo = l;
        long long hi = prefixSum.size() - 2;
        long long bestSoFar = -1;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (
                (mid - l + 1) * (prefixSum[mid + 1] - prefixSum[l]) < k
            ) {
                bestSoFar = mid;
                lo = mid + 1;
            } else { 
                hi = mid - 1;
            }
        }

        return bestSoFar;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        // First, we make a prefix sum.
        // Then, we can do binary search to find the largest vector that fits. 
        // Notice that the num values are all positive, so the numbers are monotonically increasing.

        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // for (int i = 0; i < n + 1; i++) {
        //     cout << prefixSum[i] << endl;
        // }

        long long res = 0;

        // Increment the LHS and use binary search to find the biggest RHS
        for (int l = 0; l < n; l++) {
            long long best = binarySearch(prefixSum, l, k);
            if (best == -1) {
                continue;
            }

            res += best - l + 1;
        }

        return res;
    }
};