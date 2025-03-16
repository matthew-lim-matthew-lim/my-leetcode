class Solution {
public:
    int DFS(vector<vector<int>> &memo, vector<vector<int>>& matrix, int y, int x) {
        if (memo[y][x] != 0) {
            return memo[y][x];
        }
        int n = matrix.size();
        int m = matrix[0].size();

        if (y - 1 >= 0 && matrix[y - 1][x] > matrix[y][x]) {
            memo[y][x] = max(DFS(memo, matrix, y - 1, x), memo[y][x]);
        }
        if (y + 1 < n && matrix[y + 1][x] > matrix[y][x]) {
            memo[y][x] = max(DFS(memo, matrix, y + 1, x), memo[y][x]);
        }
        if (x - 1 >= 0 && matrix[y][x - 1] > matrix[y][x]) {
            memo[y][x] = max(DFS(memo, matrix, y, x - 1), memo[y][x]);
        }
        if (x + 1 < m && matrix[y][x + 1] > matrix[y][x]) {
            memo[y][x] = max(DFS(memo, matrix, y, x + 1), memo[y][x]);
        }
        
        memo[y][x]++;
        return memo[y][x];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // BFS?
        // Must go to a strictly increasing square. 
        // Something is up, since this is a LC hard...

        // Can start and finish at any square. 
        // Priority queue with smallest values. These will be the starts for each BFS.
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> memo(n, vector<int>(m, 0));

        // DFS with memoisation.
        // Use DFS since we want to find the longest path. 
        int longestPath = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longestPath = max(longestPath, DFS(memo, matrix, i, j ));
            }
        }

        return longestPath;
    }
};