// Last updated: 4/1/2025, 11:44:09 AM
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // opt(i) is the problem of the max points starting from index i.
        // opt(i) = max(opt(i + 1), opt(i + questions[i][1]) + questions[i][0]);
        vector<long long> dp(questions.size(), 0);
        for (int i = questions.size() - 1; i >= 0; i--) {
            long long dp_adjacent = i + 1 < questions.size() ? dp[i + 1] : 0;
            long long dp_far = i + questions[i][1] + 1 < questions.size() ? dp[i + questions[i][1] + 1] : 0;
            dp[i] = max(dp_adjacent, dp_far + questions[i][0]);
        }

        return dp[0];
    }
};