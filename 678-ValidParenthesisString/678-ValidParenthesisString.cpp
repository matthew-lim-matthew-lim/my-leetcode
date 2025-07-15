// Last updated: 7/15/2025, 10:46:42 PM
/* 
Dynamic Programming.

dp[i][balance]

for each i and balance, is this valid?

balance range from 0 to n
 */

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        if (s[0] == ')') {
            return false;
        }

        dp[0][0] = s[0] == '*';
        dp[0][1] = (s[0] == '(' || s[0] == '*');

        for (int i = 1; i < n; i++) {
            char c = s[i];

            for (int b = 0; b < n; b++) {
                if (c == '(') {
                    if (b == 0) {
                        dp[i][b] = false;
                    } else {
                        dp[i][b] = dp[i - 1][b - 1];
                    }
                } else if (c == ')') {
                    dp[i][b] = dp[i - 1][b + 1];
                } else {
                    if (b == 0) {
                        dp[i][b] = dp[i - 1][b] | dp[i - 1][b + 1];
                    } else {
                        dp[i][b] = dp[i - 1][b - 1] | dp[i - 1][b] | dp[i - 1][b + 1];
                    }
                }
            }
        }

        return dp[n - 1][0];
    }
};