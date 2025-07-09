// Last updated: 7/9/2025, 9:44:29 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> pos = {0, 0};
        int n = matrix.size();
        int m = matrix[0].size();

        int R = m - 1;
        int D = n - 1;
        int L = 0;
        int U = 0;

        vector<int> res;

        while (L <= R && U <= D) {
            for (int j = L; j <= R; j++) {
                res.push_back(matrix[U][j]);
            }
            U++;
            for (int i = U; i <= D; i++) {
                res.push_back(matrix[i][R]);
            }
            R--;
            if (U <= D) {
                for (int j = R; j >= L; j--) {
                    res.push_back(matrix[D][j]);
                }
                D--;
            }
            if (L <= R) {
                for (int i = D; i >= U; i--) {
                    res.push_back(matrix[i][L]);
                }
                L++;
            }
        }

        return res;
    }
};