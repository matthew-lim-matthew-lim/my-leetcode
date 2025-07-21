// Last updated: 7/21/2025, 9:49:19 PM
/* 
Dynamic Programming.

Go from front to back.

Each index, store the cheapest to get there. 
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n && j <= i + nums[i]; j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};