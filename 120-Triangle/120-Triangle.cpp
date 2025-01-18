class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Add the weight at the ends. 
        // DP the middle weights.
        vector<int> prev_row; 
        for (int row = 1; row < triangle.size(); row++) {
            triangle[row].front() += triangle[row - 1].front();
            triangle[row].back() += triangle[row - 1].back();

            for (int i = 1; i < triangle[row].size() - 1; i++) {
                triangle[row][i] = triangle[row][i] + min(
                    triangle[row - 1][i - 1],
                    triangle[row - 1][i]
                );
            }
        }

        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};