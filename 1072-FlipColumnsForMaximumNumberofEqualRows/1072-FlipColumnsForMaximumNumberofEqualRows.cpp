class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;

        for (const auto& row : matrix) {
            string originalPattern, flippedPattern;

            // Generate both patterns for the current row
            for (int val : row) {
                originalPattern += (val == row[0] ? '1' : '0');
                flippedPattern += (val == row[0] ? '0' : '1');
            }

            // Count occurrences of both patterns
            patternCount[originalPattern]++;
            patternCount[flippedPattern]++;
        }

        // Find the largest group of rows that can be made equal
        int maxRows = 0;
        for (const auto& [pattern, count] : patternCount) {
            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};
