class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Tread the matrix like a 1D dp.
        // For each square, take the min over the ajacent sqaures + 1.
        // Repeat this until the matrix has no changes.

        bool changed = true;
        while (changed) {
            changed = false;
            
            // Vertical
            for (int i = 0; i < mat.size(); i++) {
                // Horizontal
                for (int j = 0; j < mat[0].size(); j++) {
                    if (mat[i][j] == 0) {
                        continue;
                    }

                    int min_adj = INT_MAX;
                    if (i + 1 < mat.size()) {
                        min_adj = min(min_adj, mat[i + 1][j]);
                    }
                    if (i - 1 >= 0) {
                        min_adj = min(min_adj, mat[i - 1][j]);
                    }
                    if (j + 1 < mat[0].size()) {
                        min_adj = min(min_adj, mat[i][j + 1]);
                    }
                    if (j - 1 >= 0) {
                        min_adj = min(min_adj, mat[i][j - 1]);
                    }
                    if (mat[i][j] != min_adj + 1) {
                        changed = true;
                    }
                    mat[i][j] = min_adj + 1;
                }
            }
        }

        return mat;
    }
};