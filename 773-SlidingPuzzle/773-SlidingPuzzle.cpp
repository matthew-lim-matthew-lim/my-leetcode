class Solution {
public:
    // Direction map for zero's possible moves in a flattened 1D array (2x3
    // board)
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                      {0, 4}, {3, 5, 1}, {4, 2}};

    int slidingPuzzle(vector<vector<int>>& board) {
        // DFS, storing the lowest number of moves needed to reach each arrangement. 
        // Essentially brute force.

        string start_state;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start_state += to_string(board[i][j]);
            }
        }

        // Store the min number of moves for each visited state
        unordered_map<string, int> min_moves_visit;

        dfs(start_state, min_moves_visit, start_state.find('0'), 0);

        return min_moves_visit.contains("123450") ? min_moves_visit["123450"] : -1;
    }

    void dfs(string state, unordered_map<string, int>& min_moves_visit, int zeroPos, int moves) {
        if (min_moves_visit.contains(state) && min_moves_visit[state] <= moves) {
            return;
        }
        min_moves_visit[state] = moves;

        // Try moving zero to each possible adjacent position
        for (int nextPos : directions[zeroPos]) {
            // Swap to generate new state
            swap(state[zeroPos], state[nextPos]);  
            // Recursive DFS with updated state and move count
            dfs(state, min_moves_visit, nextPos, moves + 1);  
            // Swap back to restore original state
            swap(state[zeroPos], state[nextPos]);  
        }
    }
};