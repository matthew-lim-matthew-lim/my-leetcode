// Last updated: 9/18/2025, 1:21:51 AM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int u = 0;
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;

        vector<int> res;
        while (u <= d && l <= r) {
            for (int x = l; x <= r; x++) res.push_back(matrix[u][x]);
            u++;
            for (int y = u; y <= d; y++) res.push_back(matrix[y][r]);
            r--;
            if (u <= d) {
                for (int x = r; x >= l; x--) res.push_back(matrix[d][x]);
                d--;
            }
            if (l <= r) {
                for (int y = d; y >= u; y--) res.push_back(matrix[y][l]);
                l++;
            }
        }
        return res;
    }
};