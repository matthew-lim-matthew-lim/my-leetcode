// Last updated: 7/22/2025, 12:39:29 AM
/* 
Backtracking probably.

First, put Queen in pos1 and recurse, then put Queen in pos2 and recurse, etc.

It's only 9, so we can mark the used squares.
 */

class Solution {
    int n_;
    vector<vector<int>> directions = {{1, 1}, {1, -1}, {1, 0}};
public:
    void backtrack(vector<vector<string>> &res, vector<string> currBoard, int row, vector<vector<bool>> invalidBoard) {
        int n = n_;

        if (row >= n) {
            res.push_back(currBoard);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!invalidBoard[row][i]) {
                // cout << row << " " << i << endl;
                vector<vector<bool>> newInvalid = invalidBoard;

                newInvalid[row][i] = true;
                currBoard[row][i] = 'Q';

                for (vector<int> dir : directions) {
                    int y = row;
                    int x = i;
                    for (int j = 0; j < n; j++) {
                        y += dir[0];
                        x += dir[1];
                        if (y < n && y >= 0 && x < n && x >= 0) {
                            newInvalid[y][x] = true;
                        }
                    }
                }

                backtrack(res, currBoard, row + 1, newInvalid);

                currBoard[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        n_ = n;
        vector<vector<string>> res;

        vector<string> currBoard(n, string(n, '.'));
        vector<vector<bool>> invalidBoard(n, vector(n, false));

        backtrack(res, currBoard, 0, invalidBoard);

        return res;
    }
};