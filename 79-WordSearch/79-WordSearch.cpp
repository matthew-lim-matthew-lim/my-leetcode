// Last updated: 9/17/2025, 9:40:07 PM
/* 
backtracking
 */
class Solution {
private:
    int n_;
    int m_;
    string target_;
    vector<vector<char>> board_;
    vector<vector<bool>> visited_;
public:
    bool backtrack(int y, int x, string &currword) {
        currword += board_[y][x];
        visited_[y][x] = true;
        if (currword == target_) {
            return true;
        }
        if (y + 1 < n_ && board_[y + 1][x] == target_[currword.size()] && visited_[y + 1][x] == false) {
            if (backtrack(y + 1, x, currword)) {
                return true;
            }
        } 
        if (y - 1 >= 0 && board_[y - 1][x] == target_[currword.size()] && visited_[y - 1][x] == false) {
            if (backtrack(y - 1, x, currword)) {
                return true;
            }
        }
        if (x + 1 < m_ && board_[y][x + 1] == target_[currword.size()] && visited_[y][x + 1] == false) {
            if (backtrack(y, x + 1, currword)) {
                return true;
            }
        }
        if (x - 1 >= 0 && board_[y][x - 1] == target_[currword.size()] && visited_[y][x - 1] == false) {
            if (backtrack(y, x - 1, currword)) {
                return true;
            }
        }
        visited_[y][x] = false;
        currword.pop_back();
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n_ = board.size();
        m_ = board[0].size();
        target_ = word;
        board_ = board;

        visited_ = vector<vector<bool>>(n_, vector<bool>(m_, false));

        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < m_; j++) {
                string s;
                if (backtrack(i, j, s)) {
                    return true;
                }
            }
        }

        return false;
    }
};