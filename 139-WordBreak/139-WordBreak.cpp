// Last updated: 9/17/2025, 11:35:30 PM
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
                cout << word << endl;
                cout << "1 " << endl;
                bool valid = true;
                cout << int(i - word.size() + 1) << endl;
                if (int(i - word.size() + 1) < 0) {
                    cout << "hey" << endl;
                    continue;
                }

                cout << "2 " << endl;
                for (int j = 0; j < word.size(); j++) {
                    cout << "a" << endl;
                    if (s[i - word.size() + 1 + j] != word[j]) {
                        valid = false;
                        break;
                    }
                }

                cout << "3 " << endl;
                cout << word << " " << valid << endl;
                if (valid) {
                    if (i - word.size() == -1) {
                        dp[i] = true;
                    } else {
                        dp[i] = dp[i] | dp[i - word.size()];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << dp[i] << " ";
        }

        return dp[n - 1];
    }
};