class Solution {
public:
    int solve(int i, int j, int &m, int &n, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i >= m && j >= n) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        else if(i >= m) {
            dp[i][j] = solve(i, j + 1, m, n, s1, s2, dp);
        }
        else if(j >= n) {
            dp[i][j] = solve(i + 1, j, m, n, s1, s2, dp);
        }
        else {
            if(s1[i] == s2[j]) {
                dp[i][j] = 1 + solve(i + 1, j + 1, m, n, s1, s2, dp);
            }
            else {
                dp[i][j] = max(solve(i, j + 1, m, n, s1, s2, dp), solve(i + 1, j, m, n, s1, s2, dp));
            }
        }
        return dp[i][j];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        solve(0, 0, m, n, str1, str2, dp);
        string ans = "";
        int i = 0, j = 0;
        while(i < m || j < n) {
            if(i >= m) {
                ans = ans + str2[j];
                j++;
            }
            else if(j >= n) {
                ans = ans + str1[i];
                i++;
            }
            else {
                if(str1[i] == str2[j]) {
                    ans = ans + str1[i];
                    i++;
                    j++;
                }
                else {
                    if(dp[i + 1][j] > dp[i][j + 1]) {
                        ans = ans + str1[i];
                        i++;
                    }
                    else {
                        ans = ans + str2[j];
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};