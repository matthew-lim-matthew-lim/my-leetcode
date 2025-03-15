class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<int> currPos = { 0, 0 };
        vector<int> order;
        
        vector<vector<int>> direction = {{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }};
        int d = 0;
        while (true) {
            order.push_back(matrix[currPos[0]][currPos[1]]);
            visited[currPos[0]][currPos[1]] = true;
            
            vector<int> newPos = { currPos[0] + direction[d][0], currPos[1] + direction[d][1] };
            if (newPos[0] < n && newPos[1] < m && newPos[0] >= 0 && newPos[1] >= 0 && visited[newPos[0]][newPos[1]] == false) {
                currPos = newPos;
            } else {
                d = (d + 1) % 4;
                vector<int> newPos = { currPos[0] + direction[d][0], currPos[1] + direction[d][1] };
                if (!(newPos[0] < n && newPos[1] < m && newPos[0] >= 0 && newPos[1] >= 0 && visited[newPos[0]][newPos[1]] == false)) {
                    return order;
                }
                currPos = newPos;
            }
        }

        return order;
    }
};