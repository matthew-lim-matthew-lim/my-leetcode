class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long cell_sum = 0;
        int min_cell_val = INT_MAX;
        int cell_negative_count = 0;

        for (vector<int>& row : matrix) {
            for (int& cell : row) {
                if (cell < 0) {
                    cell_negative_count++;
                } 
                cell_sum += abs(cell);
                min_cell_val = min(min_cell_val, abs(cell));
            }
        }

        if (cell_negative_count % 2 == 0) {
            return cell_sum;
        } else {
            return cell_sum - min_cell_val * 2;
        }
    }
};