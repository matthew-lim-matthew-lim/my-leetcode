// Last updated: 9/15/2025, 10:20:53 PM
/* 
Dynamic programming
dp[i][j]
Where 'i' is the index, and 'j' is the number of excess '(' there are.
 */
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        if (s[0] == ')') {
            return false;
        }
        if (s[0] == '(') {
            dp[0][1] = true;
        }
        if (s[0] == '*') {
            dp[0][0] = true;
            dp[0][1] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool left = j - 1 >= 0 && dp[i - 1][j - 1];
                bool right = j + 1 < n && dp[i - 1][j + 1];
                if (s[i] == '(') {
                    dp[i][j] = left;
                }
                if (s[i] == ')') {
                    dp[i][j] = right;
                }
                if (s[i] == '*') {
                    dp[i][j] = left || right || dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][0];
    }
};