class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Sliding window to get the values starting at each
        // position.
        // DP to select each starting position without overlap.
        // dp[i, 3] = max(dp[i - k, 2] + startVal[i], dp[i - 1, 3]);

        // Precompute values starting at each index
        vector<int> startVal(nums.size(), 0);
        int currSum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            currSum += nums[i];
            if (i < nums.size() - k) {
                currSum -= nums[i + k];
            }
            startVal[i] = currSum;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << startVal[i] << " ";
        }
        cout << endl; 
        cout << endl;

        // Use DP to get the max result when taking from each index.
        vector<vector<int>> dp(nums.size(), vector<int>(4, 0));
        // dp[i, j] = max(dp[i - k, j - 1] + startVal[i], dp[i - 1, j]);
        // Prev map
        // vector<vector<int>> prev(nums.size(), vector<int>(4, -1));
        // For each increasing j, compute increasing i. 
        int max_index = 0;
        
        // Map prev[j][val] to get the lowest index for each value
        vector<unordered_map<int, int>> prev(4);
        
        for (int j = 1; j < 4; j++) {
            // j = 0 means 0 taken, j = 1 means 1 taken, etc.
            int prev_taken = -1;
            unordered_map<int, int> this_row_val_to_index;
            for (int i = 0; i < nums.size(); i++) {
                cout << "i: " << i << endl;
                int take_this = i - k >= 0 ? dp[i - k][j - 1] + startVal[i] : startVal[i];
                int skip_this = i - 1 >= 0 ? dp[i - 1][j] : -1;
                // dp[i][j] = max(take_this.first, skip_this.first);
                // if (j == 1) {
                //     cout << i << endl;
                //     cout << take_this.first << " " << skip_this.first << endl;
                //     cout << take_this.second << " " << skip_this.second << endl;
                // }
                // if (this_row_val_to_index.contains(take_this)) {
                //     this_row_val_to_index[take_this] = min(this_row_val_to_index[take_this], i);
                // } else {
                //     this_row_val_to_index[take_this] = i;
                // }
                // if (this_row_val_to_index.contains(skip_this)) {
                //     this_row_val_to_index[skip_this] = min(this_row_val_to_index[skip_this], i);
                // } else {
                //     this_row_val_to_index[skip_this] = i;
                // }
                if (take_this > skip_this) {
                    dp[i][j] = take_this;

                    // prev[i][j] = take_this.second;
                    // prev_taken = take_this.second;

                    // Map the value to the smallest index that gets this value. 
                    if (take_this == 11) {
                        cout << i - k << " res" << endl;
                    }
                    if (prev[j].contains(take_this)) {
                        prev[j][take_this] = min(prev[j - 1][take_this], i);
                    } else {
                        prev[j][take_this] = i;
                    }
                    max_index = i;
                } else {
                    // dp[i][j] = skip_this.first;
                    // prev[i][j] = prev_taken;
                    dp[i][j] = skip_this;
                }
            }
        }

        // for (int i = 0; i < nums.size(); i++) {
        //     cout << dp[i][3] << endl;
        // }

        for (int j = 0; j < 4; j++) {
            for (pair<int, int> p : prev[j]) {
                cout << "{" << p.first << " " << p.second << "} ";
            }
            cout << endl;
        }

        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < nums.size(); i++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        int curr_val = dp[max_index][3];
        vector<int> path(3, -1);
        for (int j = 3; j >= 1; j--) {
            path[j - 1] = prev[j][curr_val];
            curr_val -= startVal[prev[j][curr_val]];
        }

        return path;
    }
};