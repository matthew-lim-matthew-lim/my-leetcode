// Last updated: 4/25/2025, 1:37:16 AM
class Solution {
public:
// Oh hell nah
// dp[i] is the number of ways decoding the string up to index i.
// dp[i] = dp[i - 1] (if `s[0]` is a valid number) + dp[i - 2] (if `s[0] + s[1]` is a valid number);
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            // First char always legit.
            int oneDigit = i - 1 == -1 ? 1 : dp[i - 1];
            oneDigit = s[i] != '0' ? oneDigit : 0;

            // Second char
            int twoDigit = 0;
            if (i - 1 >= 0) {
                twoDigit = i - 2 == -1 ? 1 : dp[i - 2];
                twoDigit = i - 1 >= 0 && stoi(string{s[i - 1], s[i]}) >= 10 && stoi(string{s[i - 1], s[i]}) <= 26 ? twoDigit : 0;
            }
            
            dp[i] = oneDigit + twoDigit;
        }

        return dp[n - 1];
    }
};