class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2, -1);
        // Can I do it with constant memory? Maybe not
        vector<bool> numSet(n * n + 1, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int currNum = grid[i][j];
                if (numSet[currNum] == true) {
                    res[0] = currNum;
                } else {
                    numSet[currNum] = true;
                }
            }
        }
        for (int i = 1; i < n * n + 1; i++) {
            if (numSet[i] == false) {
                res[1] = i;
            }
        }

        return res;
    }
};