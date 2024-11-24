class Solution {
public:
    void diagonal_processing(vector<vector<int>>& curr_available, int n, int y, int x, int y_dir, int x_dir, int delta) {
        int curr_y = y;
        int curr_x = x;
        while (curr_y < n &&
                curr_y >= 0 && 
                curr_x < n 
                && curr_x >= 0
        ) {
            curr_available[curr_y][curr_x] += delta;
            curr_y += y_dir;
            curr_x += x_dir;
        }
    }

    void increment_hits(vector<vector<int>>& curr_available, int n, int y, int x) {
        // Increment hits on row, col, and diagonal
        // Row and col
        for (int i = 0; i < n; i++) {
            curr_available[y][i]++;
            curr_available[i][x]++;
        }

        // Diagonals
        diagonal_processing(curr_available, n, y, x, 1, 1, 1);
        diagonal_processing(curr_available, n, y, x, -1, 1, 1);
        diagonal_processing(curr_available, n, y, x, 1, -1, 1);
        diagonal_processing(curr_available, n, y, x, -1, -1, 1);

        // The current square was counted 6 times.
        curr_available[y][x] -= 5;
    }

    void decrement_hits(vector<vector<int>>& curr_available, int n, int y, int x) {
        // Increment hits on row, col, and diagonal
        // Row and col
        for (int i = 0; i < n; i++) {
            curr_available[y][i]--;
            curr_available[i][x]--;
        }

        // Diagonals
        diagonal_processing(curr_available, n, y, x, 1, 1, -1);
        diagonal_processing(curr_available, n, y, x, -1, 1, -1);
        diagonal_processing(curr_available, n, y, x, 1, -1, -1);
        diagonal_processing(curr_available, n, y, x, -1, -1, -1);

        // The current square was counted 6 times.
        curr_available[y][x] += 5;
    }

    void backtrack(vector<vector<string>>& res, 
                    vector<vector<int>>& curr_available, 
                    vector<string>& curr_res, 
                    int n, 
                    int queen_count,
                    int curr_y,
                    int curr_x
    ) {
        if (queen_count == n) {
            res.push_back(curr_res);
            return;
        }

        for (int i = curr_y; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (curr_available[i][j] > 0) {
                    continue;
                }
                curr_res[i][j] = 'Q';
                increment_hits(curr_available, n, i, j);
                backtrack(res, curr_available, curr_res, n, queen_count + 1, i, j);
                decrement_hits(curr_available, n, i, j);
                curr_res[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Took 55:00
        // Was really tricky to think of a nice way to do it, but realise that bruteforcing with backtracking
        // could be a straightforward way as long as there is a way to track the available squares.

        // Restrictions:
        // No 2 queens on same row. 
        // No 2 queens on same column.
        // No 2 queens on same diagonal. 
        vector<vector<string>> res;
        // The current board with just the Queens and '.'
        vector<string> curr_res(n, string(n, '.'));
        // The current board availabilities, where 'x' is for the squares that can't be occupied. 
        vector<vector<int>> curr_available(n, vector<int>(n, 0));

        int queen_count = 0;

        backtrack(res, curr_available, curr_res, n, queen_count, 0, 0);

        return res;
    }
};