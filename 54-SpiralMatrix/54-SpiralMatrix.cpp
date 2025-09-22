// Last updated: 9/23/2025, 12:25:45 AM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size() - 1;
        int u = 0;
        int d = matrix.size() - 1;

        vector<int> res;
        while (l <= r && u <= d) {
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[u][i]);
            }
            u++;
            for (int i = u; i <= d; i++) {
                res.push_back(matrix[i][r]);
            }
            r--;
            if (l <= r && u <= d) {
                for (int i = r; i >= l; i--) {
                    res.push_back(matrix[d][i]);
                }
                d--;
                for (int i = d; i >= u; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return res;
    }
};