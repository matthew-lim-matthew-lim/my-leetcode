// Last updated: 4/10/2025, 10:04:05 PM
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Get the sum of each deletion possibility in a map. 
        // Then this problem becomes like house robber - You can't keep two adjacent numbers. 
        // House robber was like dp[i] = max(dp[i - 1], dp[i - 2] + numsSum[i]);
        // In this problem, use a dp map. 
        int res = 0;

        unordered_map<int, int> numsSum;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            numsSum[nums[i]] += nums[i];
        }

        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        vector<int> dp(end + 1, 0);

        // Now, each value of nums[i] is stored in the map.
        for (int i = start; i <= end; i++) {
            // dp[i - 1]
            int L1 = (i - 1 >= 0) ? dp[i - 1] : 0;

            int L2 = (i - 2 >= 0) ? dp[i - 2] + numsSum[i] : 0;

            int X = numsSum[i];

            dp[i] = max(X, max(L1, L2));
            res = max(res, dp[i]);
        } 

        return res;
    }
};