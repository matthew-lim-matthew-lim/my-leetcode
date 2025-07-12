// Last updated: 7/12/2025, 11:43:42 PM
/* 
Backtracking. 


*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        function<bool(int, int, string&)> backtrack = [&](int i, int j, string& currWord) {
            if (currWord.size() < word.size() && board[i][j] != word[currWord.size()]) {
                return false;
            }

            visited[i][j] = true;
            currWord += board[i][j];

            if (currWord == word) {
                return true;
            }

            for (int k = 0; k < 4; k++) {
                int y = i + directions[k][0];
                int x = j + directions[k][1];
                if (y < n && y >= 0 && x < m && x >= 0 && !visited[y][x]) {
                    if (backtrack(y, x, currWord)) {
                        return true;
                    }
                }
            }

            visited[i][j] = false;
            currWord.pop_back();

            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string s;
                if (backtrack(i, j, s)) {
                    return true;
                } 
            }
        }

        return false;
    }
};