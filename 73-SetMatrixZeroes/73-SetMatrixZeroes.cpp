// Last updated: 5/21/2025, 6:26:12 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroInFirstCol = false;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) zeroInFirstCol = true;

            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (zeroInFirstCol) {
                matrix[i][0] = 0;
            }
        }
    }
};