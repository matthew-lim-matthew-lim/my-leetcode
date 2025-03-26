// Last updated: 3/26/2025, 8:59:43 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Make it into an array.
        // 2, 0, 2, 4
        // 4, 2, 0, 2
        // 20 / 4 = 5.

        // 1, 5, 2, 3 = 11.
        // 11 / 4 = 2.75

        // Each element has a distance from a particular element. 
        
        // Maybe binary search?
        // Binary search on the number of operations we can do.
        
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr(n * m, 0);

        int remainder = grid[0][0] % x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i * m + j] = grid[i][j];
                if (grid[i][j] % x != remainder) {
                    return -1;
                }
            }
        }  
        sort(arr.begin(), arr.end());
        
        int target = arr[(n * m) / 2];

        int moves = 0;
        for (int i = 0; i < n * m; i ++) {
            moves += abs(target - arr[i]) / x;
        }  

        return moves;
    }
};