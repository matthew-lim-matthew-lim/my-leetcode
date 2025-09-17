// Last updated: 9/17/2025, 11:36:06 PM
/* 
dp[i] represents if it is possible to use wordDict to construct to 'i'.
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);

        for (int i = 0; i < n; i++) {
            for (string &word : wordDict) {
                bool valid = true;
                if (int(i - word.size() + 1) < 0) {
                    continue;
                }

                for (int j = 0; j < word.size(); j++) {
                    if (s[i - word.size() + 1 + j] != word[j]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    if (i - word.size() == -1) {
                        dp[i] = true;
                    } else {
                        dp[i] = dp[i] | dp[i - word.size()];
                    }
                }
            }
        }

        return dp[n - 1];
    }
};