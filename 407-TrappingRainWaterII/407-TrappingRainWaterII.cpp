class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // By using a pq to represent the boundary, we make sure that the height of each body of water
        // is at the height of the shortest boundary.
        // { height, x, y }
        int numRows = heightMap.size();
        int numCols = heightMap[0].size();
        priority_queue<vector<int>, std::vector<std::vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(heightMap.size(), vector<bool>(heightMap[0].size(), false));

        // Add top and bottom rows
        for (int i = 0; i < numCols; i++) {
            pq.push({ heightMap[0][i], 0, i });
            pq.push({ heightMap[numRows - 1][i], numRows - 1, i });
            visited[0][i] = true;
            visited[numRows - 1][i] = true;
        }
        // Add left and right cols
        for (int i = 0; i < numRows; i++) {
            pq.push({ heightMap[i][0], i, 0 });
            pq.push({ heightMap[i][numCols - 1], i, numCols - 1 });
            visited[i][0] = true;
            visited[i][numCols - 1] = true;
        }

        // Use BFS to process the boundary squares. 
        int res = 0;

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int minBoundaryHeight = curr[0];

            if (curr[1] + 1 < numRows && !visited[curr[1] + 1][curr[2]]) {
                int neighbourHeight = heightMap[curr[1] + 1][curr[2]];
                if (neighbourHeight < minBoundaryHeight) {
                    res += minBoundaryHeight - neighbourHeight;
                }

                // Push onto pq with new boundary height so that this boundary is used for rest of water
                pq.push({ max(neighbourHeight, minBoundaryHeight), curr[1] + 1, curr[2] });
                visited[curr[1] + 1][curr[2]] = true;
            }
            if (curr[1] - 1 >= 0 && !visited[curr[1] - 1][curr[2]]) {
                int neighbourHeight = heightMap[curr[1] - 1][curr[2]];
                if (neighbourHeight < minBoundaryHeight) {
                    res += minBoundaryHeight - neighbourHeight;
                }

                // Push onto pq with new boundary height so that this boundary is used for rest of water
                pq.push({ max(neighbourHeight, minBoundaryHeight), curr[1] - 1, curr[2] });
                visited[curr[1] - 1][curr[2]] = true;
            }
            if (curr[2] + 1 < numCols && !visited[curr[1]][curr[2] + 1]) {
                int neighbourHeight = heightMap[curr[1]][curr[2] + 1];
                if (neighbourHeight < minBoundaryHeight) {
                    res += minBoundaryHeight - neighbourHeight;
                }

                // Push onto pq with new boundary height so that this boundary is used for rest of water
                pq.push({ max(neighbourHeight, minBoundaryHeight), curr[1], curr[2] + 1 });
                visited[curr[1]][curr[2] + 1] = true;
            }
            if (curr[2] - 1 >= 0 && !visited[curr[1]][curr[2] - 1]) {
                int neighbourHeight = heightMap[curr[1]][curr[2] - 1];
                if (neighbourHeight < minBoundaryHeight) {
                    res += minBoundaryHeight - neighbourHeight;
                }

                // Push onto pq with new boundary height so that this boundary is used for rest of water
                pq.push({ max(neighbourHeight, minBoundaryHeight), curr[1], curr[2] - 1 });
                visited[curr[1]][curr[2] - 1] = true;
            }
        }

        return res;
    }
};