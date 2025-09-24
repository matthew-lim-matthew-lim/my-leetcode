// Last updated: 9/24/2025, 9:12:56 PM
class Solution {
public:
    // int bs(vector<int>& arr, int x){
    //     int low = 0; int high = arr.size();
    //     while(low <= high){
    //         int mid = (low+high)/2;
    //         if (arr[mid] == x) return 1;
    //         else if (arr[mid] > x) high = mid -1;
    //         else low = mid + 1;
    //     }
    //     return 0;
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int rows = matrix.size();
        // int cols = matrix[0].size();
        // int ans = -1;
        // for (int i = 0; i < rows; i++) {
        //     if (matrix[i][0] <= target && target <= matrix[i][cols-1]) {
        //         ans = bs(matrix[i], target);
        //     }else continue;
        // }

        // return ans == 1 ? true: false;
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0; int high = (n*m) - 1;
        while (low <= high) {
            int mid = (low+high)/2;
            int midrow = mid / m;
            int midcol = mid % m;
            int midEl = matrix[midrow][midcol];
            if (midEl == target) return true;
            else if (midEl > target) high = mid - 1;
            else low = mid + 1;
        }

        return false;
    }
};