// Last updated: 7/16/2025, 5:59:46 PM
/* 
Adjacent values must be either:
- All the same parity.
- OR Alternating parity.

Even/Odd prev even -> AEVEN
Even/Odd prev odd -> AODD
Even only -> EVEN
Odd only -> ODD
 */
class Solution {
private:
    const static int AEVEN = 0;
    const static int AODD = 1;
    const static int EVEN = 2;
    const static int ODD = 3;

public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][AEVEN] = nums[0] % 2 == 0;
        dp[0][AODD] = nums[0] % 2 == 1;
        dp[0][EVEN] = nums[0] % 2 == 0;
        dp[0][ODD] = nums[0] % 2 == 1;    

        for (int i = 1; i < n; i++) {
            dp[i][AEVEN] = (nums[i] % 2 == 0) ? max(dp[i - 1][AODD] + 1, dp[i - 1][AEVEN]) : dp[i - 1][AEVEN];
            dp[i][AODD] = (nums[i] % 2 == 1) ? max(dp[i - 1][AEVEN] + 1, dp[i - 1][AODD]) : dp[i - 1][AODD];
            dp[i][EVEN] = dp[i - 1][EVEN] + (nums[i] % 2 == 0);
            dp[i][ODD] = dp[i - 1][ODD] + (nums[i] % 2 == 1);
        }

        

        return max({dp[n - 1][AEVEN], dp[n - 1][AODD], dp[n - 1][EVEN], dp[n - 1][ODD]});
    }
};