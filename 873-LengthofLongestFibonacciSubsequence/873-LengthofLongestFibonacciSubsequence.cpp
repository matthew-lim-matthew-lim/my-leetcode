class Solution {
public:
    int solve(int x1_idx, int x2_idx, vector<int> &arr, unordered_map<int, int> &numIdx, vector<vector<int>> &dp) {
        if(dp[x1_idx][x2_idx] != -1) {
            return dp[x1_idx][x2_idx];
        }
        dp[x1_idx][x2_idx] = 1;
        if(numIdx.find(arr[x1_idx] + arr[x2_idx]) != numIdx.end()) {
            dp[x1_idx][x2_idx] += solve(x2_idx, numIdx[arr[x1_idx] + arr[x2_idx]], arr, numIdx, dp);
        }
        return dp[x1_idx][x2_idx];
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        unordered_map<int, int> numIdx;
        for(int idx = 0; idx < n; idx++) {
            numIdx[arr[idx]] = idx;
        }
        int ans = 0;
        for(int x1_idx = 0; x1_idx < n; x1_idx++) {
            for(int x2_idx = x1_idx + 1; x2_idx < n; x2_idx++) {
                ans = max(ans, 1 + solve(x1_idx, x2_idx, arr, numIdx, dp));
            }
        }
        return ans == 2 ? 0 : ans;
    }
};