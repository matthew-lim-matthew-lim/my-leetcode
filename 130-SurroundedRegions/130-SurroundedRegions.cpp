class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Basically any 'O' that isn't connected to an 'O' that is on the edge of the board. 
        // If a region has an 'O' that is on the edge of the board, then we cannot change it.
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == true) continue;
                visited[i][j] = true;
                if (board[i][j] == 'X') continue;

                queue<pair<int, int>> q;
                q.push({ i , j });
                queue<pair<int, int>> currRegion;
                currRegion.push({ i, j });
                bool surrounded = false;
                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    int y = curr.first;
                    int x = curr.second;
                    currRegion.push({ y, x });
                    if (y == 0 || y == n - 1 || x == 0 || x == m - 1) surrounded = true;

                    if (y + 1 < n && visited[y + 1][x] == false && board[y + 1][x] == 'O') {
                        q.push({ y + 1, x });
                        visited[y + 1][x] = true;
                    }
                    if (y - 1 >= 0 && visited[y - 1][x] == false && board[y - 1][x] == 'O') {
                        q.push({ y - 1, x });
                        visited[y - 1][x] = true;
                    }
                    if (x + 1 < m && visited[y][x + 1] == false && board[y][x + 1] == 'O') {
                        q.push({ y, x + 1 });
                        visited[y][x + 1] = true;
                    }
                    if (x - 1 >= 0 && visited[y][x - 1] == false && board[y][x - 1] == 'O') {
                        q.push({ y, x - 1 });
                        visited[y][x - 1] = true;
                    }
                }

                if (!surrounded) {
                    while (!currRegion.empty()) {
                        pair<int, int> curr = currRegion.front();
                        currRegion.pop();

                        board[curr.first][curr.second] = 'X';
                    }
                }
            }
        }
    }
};