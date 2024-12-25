class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0 && s2 != s3) return false;
        if (s2.size() == 0 && s1 != s3) return false;
        if (s3.size() == 0 && s1.size() == 0 && s2.size() == 0) return true; 
        if (s1.size() + s2.size() != s3.size()) return false;
        // opt(i, j) = opt(i - 1, j) && s3[i + j] == s1[i] || opt(i, j - 1) && s3[i + j] == s2[j];
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        // for (int i = 0; i < s1.size() + 1; i++) {
        //     dp[i][0] = true;
        // }
        // for (int j = 0; j < s2.size() + 1; j++) {
        //     dp[0][j] = true;
        // }
        dp[0][0] = true;
        for (int i = 1; i <= s1.size(); i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for (int j = 1; j <= s2.size(); j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }

        for (int i = 1; i < s1.size() + 1; i++) {
            for (int j = 1; j < s2.size() + 1; j++) {
                if (i == 0 && j == 0) continue;

                bool up = dp[i - 1][j] && s3[i + j - 1] == s1[i - 1];
                bool left = dp[i][j - 1] && s3[i + j - 1] == s2[j - 1];

                dp[i][j] = up || left;
            }
        }

        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[s1.size()][s2.size()];
    }
};