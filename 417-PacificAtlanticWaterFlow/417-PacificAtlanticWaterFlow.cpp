class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Find all the cells that can reach the Pacific Ocean. Then, find all the cells
        // that can reach the Atlantic Ocean. 
        // Return the intersection of the groups. 

        // Finding cells that can reach the Pacific Ocean: 
        // Start at TOP and LEFT edges, adding them to a BFS queue. 
        // Allow the BFS to explore, only allowing travel to adjacent squares with greater height.
        unordered_map<int, unordered_set<int>> pacific_visited;
        stack<pair<int, int>> bfsStack;
        bfsStack.push({ 0, 0 });
        pacific_visited[0].insert(0);
        for (int i = 1; i < heights.size(); i++) {
            bfsStack.push({i, 0});
            pacific_visited[i].insert(0);
        }
        for (int i = 1; i < heights[0].size(); i++) {
            bfsStack.push({ 0, i });
            pacific_visited[0].insert(i);
        }
        while (!bfsStack.empty()) {
            pair<int, int> curr = bfsStack.top();
            bfsStack.pop();

            int y = curr.first;
            int x = curr.second;

            if (y + 1 < heights.size() && 
                heights[y + 1][x] >= heights[y][x] && 
                (!pacific_visited.contains(y + 1) || !pacific_visited[y + 1].contains(x))
            ) {
                bfsStack.push({ y + 1, x });
                pacific_visited[y + 1].insert(x);
            }
            if (y - 1 >= 0 && 
                heights[y - 1][x] >= heights[y][x] && 
                (!pacific_visited.contains(y - 1) || !pacific_visited[y - 1].contains(x))
            ) {
                bfsStack.push({ y - 1, x });
                pacific_visited[y - 1].insert(x);
            }
            if (x + 1 < heights[0].size() && 
                heights[y][x + 1] >= heights[y][x] && 
                (!pacific_visited.contains(y) || !pacific_visited[y].contains(x + 1))
            ) {
                bfsStack.push({ y, x + 1 });
                pacific_visited[y].insert(x + 1);
            }
            if (x - 1 >= 0 && 
                heights[y][x - 1] >= heights[y][x] && 
                (!pacific_visited.contains(y) || !pacific_visited[y].contains(x - 1))
            ) {
                bfsStack.push({ y, x - 1 });
                pacific_visited[y].insert(x - 1);
            }
        }
        
        // Finding cells that can reach the Atlantic Ocean
        unordered_map<int, unordered_set<int>> atlantic_visited;
        bfsStack.push({ heights.size() - 1, heights[0].size() - 1 });
        atlantic_visited[heights.size() - 1].insert(heights[0].size() - 1);
        for (int i = 0; i < heights.size() - 1; i++) {
            bfsStack.push({i, heights[0].size() - 1});
            atlantic_visited[i].insert(heights[0].size() - 1);
        }
        for (int i = 0; i < heights[0].size() - 1; i++) {
            bfsStack.push({ heights.size() - 1, i });
            atlantic_visited[heights.size() - 1].insert(i);
        }
        while (!bfsStack.empty()) {
            pair<int, int> curr = bfsStack.top();
            bfsStack.pop();

            int y = curr.first;
            int x = curr.second;

            if (y + 1 < heights.size() && 
                heights[y + 1][x] >= heights[y][x] && 
                (!atlantic_visited.contains(y + 1) || !atlantic_visited[y + 1].contains(x))
            ) {
                bfsStack.push({ y + 1, x });
                atlantic_visited[y + 1].insert(x);
            }
            if (y - 1 >= 0 && 
                heights[y - 1][x] >= heights[y][x] && 
                (!atlantic_visited.contains(y - 1) || !atlantic_visited[y - 1].contains(x))
            ) {
                bfsStack.push({ y - 1, x });
                atlantic_visited[y - 1].insert(x);
            }
            if (x + 1 < heights[0].size() && 
                heights[y][x + 1] >= heights[y][x] && 
                (!atlantic_visited.contains(y) || !atlantic_visited[y].contains(x + 1))
            ) {
                bfsStack.push({ y, x + 1 });
                atlantic_visited[y].insert(x + 1);
            }
            if (x - 1 >= 0 && 
                heights[y][x - 1] >= heights[y][x] && 
                (!atlantic_visited.contains(y) || !atlantic_visited[y].contains(x - 1))
            ) {
                bfsStack.push({ y, x - 1 });
                atlantic_visited[y].insert(x - 1);
            }
        }

        vector<vector<int>> res;
        for (const pair<int, unordered_set<int>>& entry : pacific_visited) {
            int y = entry.first;
            for (int x : entry.second) {
                if (atlantic_visited.contains(y) && atlantic_visited[y].contains(x)) {
                    res.push_back({ y, x });
                }
            }
        }

        return res;
    }
};