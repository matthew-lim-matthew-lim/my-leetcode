class Solution {
public:
    int countSubstrings(string s) {
        int substring_count = 0;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            substring_count++;
            if (i + 1 < s.size() && (s[i] == s[i + 1])) {
                dp[i][i + 1] = true;
                substring_count++;
            }
        }

        // Iterate through by length of the palindrome: 1, 2, 3, etc.
        // Iterate through by increasing (j - i).
        // i is the left pointer, j is the right pointer. 
        // dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
        // diff = j - i;
        for (int diff = 2; diff < s.size(); diff++) {
            for (int i = 0; i < s.size() - diff; i++) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    substring_count++;
                }
            }
        }

        return substring_count;
    }
};