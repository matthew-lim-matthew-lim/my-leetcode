// Last updated: 9/24/2025, 9:07:21 PM
/* 
Whenever we have a mismatch, we can eliminate a rectangle of numbers. 
Eg. if matrix[i][j] < target, then eliminate matrix[0..i][0..j].
If matrix[i][j] > target, then eliminate matrix[i..n-1][j..m-1].

This is now a recursion problem with 3 rectangular search areas.
 */
class Solution {
private:
    int target_;
    vector<vector<int>> matrix_;
    int n_;
    int m_;
public:
    bool search(int tly, int tlx, int bry, int brx) {
        // cout << tly << " " << tlx << " " << bry << " " << brx << endl;
        if (tly > bry || tlx > brx || 
            bry >= n_ || bry < 0 || tly >= n_ || tly < 0 ||
            tlx >= m_ || tlx < 0 || brx >= m_ || brx < 0
        ) {
            return false;
        }
        int midy = (tly + bry) / 2;
        int midx = (tlx + brx) / 2;

        if (matrix_[midy][midx] > target_) {
            // Eliminate bottom-right
            return search(tly, tlx, midy - 1, midx - 1) ||
                search(tly, midx, midy - 1, brx) ||
                search(midy, tlx, bry, midx - 1);
        } else if (matrix_[midy][midx] < target_) {
            // Eliminate top-left
            return search(midy + 1, midx + 1, bry, brx) ||
                search(tly, midx + 1, midy, brx) ||
                search(midy + 1, tlx, bry, midx);
        }
        return true;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n_ = matrix.size();
        m_ = matrix[0].size();

        target_ = target;
        matrix_ = matrix;

        return search(0, 0, n_ - 1, m_ - 1);
    }
};