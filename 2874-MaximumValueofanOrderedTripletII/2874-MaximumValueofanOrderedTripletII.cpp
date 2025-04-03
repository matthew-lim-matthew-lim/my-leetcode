// Last updated: 4/3/2025, 6:27:42 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // Precompute 
        int n = nums.size();
        vector<int> largestLeft(n, 0);
        vector<int> largestRight(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                largestLeft[i] = nums[i];
                largestRight[(n - 1) - i] = nums[(n - 1) - i];
            } else {
                largestLeft[i] = max(nums[i], largestLeft[i - 1]);
                largestRight[(n - 1) - i] = max(nums[(n - 1) - i], largestRight[(n - 1) - i + 1]);
            }
        }

        // Now, go through 
        long long best = 0;

        for (int i = 1; i < n - 1; i++) {
            best = max(best, (long long)((long long)(largestLeft[i - 1] - nums[i]) * largestRight[i + 1]));
        }

        return best;
    }
};