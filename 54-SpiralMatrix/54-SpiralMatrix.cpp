// Last updated: 7/9/2025, 8:50:42 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<int>> direction = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<int> pos = {0, 0};
        int currD = 0;

        while (true) {
            if (visited[pos[0]][pos[1]] == 0) {
                res.push_back(matrix[pos[0]][pos[1]]);
            }
            // cout << pos[0] << ", " << pos[1] << " " << visited[pos[0]][pos[1]] << endl;
            visited[pos[0]][pos[1]]++;
            if (pos[0] + direction[currD][0] < n && 
                pos[0] + direction[currD][0] >= 0 &&
                pos[1] + direction[currD][1] < m &&
                pos[1] + direction[currD][1] >= 0 &&
                visited[pos[0] + direction[currD][0]][pos[1] + direction[currD][1]] == 0
            ) {
                pos[0] += direction[currD][0];
                pos[1] += direction[currD][1];
            }    
            else {
                currD++;
                currD %= 4;
            }

            if (visited[pos[0]][pos[1]] > 4) {
                return res;
            }
        }

        return res;
    }
};