// Last updated: 4/13/2025, 11:15:43 PM
class Solution {
public:
    void print(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        // I think do swaps. 
        // 1 2
        // 3 4
        // 
        // 3 1
        // 4 2
        // swap(TL, BL)
        // swap(BL, TR)
        // swap(BL, BR)
        int n = matrix.size();
        int mid = ceil(n / 2.0);

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < ceil(n / 2.0); j++) {
                swap(matrix[i][j], matrix[(n - 1) - j][i]);
                swap(matrix[(n - 1) - j][i], matrix[j][(n - 1) - i]);
                swap(matrix[(n - 1) - j][i], matrix[(n - 1) - i][(n - 1) - j]);
            }
        }

        // print(matrix);

        // if (n % 2 == 1) {
        //     int i = n / 2;
        //     int j = n / 2;
        //     cout << i << endl;
        //     swap(matrix[i][j], matrix[(n - 1) - j][i]);
        //     swap(matrix[(n - 1) - j][i], matrix[j][(n - 1) - i]);
        //     swap(matrix[(n - 1) - j][i], matrix[(n - 1) - i][(n - 1) - j]);
        // }

        // print(matrix);

        return;
    }
};