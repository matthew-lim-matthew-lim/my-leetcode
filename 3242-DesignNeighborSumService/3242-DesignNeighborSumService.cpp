// Last updated: 4/21/2026, 12:51:25 AM
1class NeighborSum {
2private:
3    vector<vector<int>> grid_;
4    unordered_map<int, int> adjSumMap_;
5    unordered_map<int, int> diagSumMap_;
6public:
7    NeighborSum(vector<vector<int>>& grid) : grid_(grid) {
8        int n = grid_.size();
9        int m = grid_[0].size();
10
11        for (int i = 0; i < n; i++) {
12            for (int j = 0; j < m; j++) {
13                int adj = 0;
14                if (i + 1 < n) {
15                    adj += grid_[i+1][j];
16                }
17                if (i - 1 >= 0) {
18                    adj += grid_[i-1][j];
19                }
20                if (j + 1 < m) {
21                    adj += grid_[i][j+1];
22                }
23                if (j - 1 >= 0) {
24                    adj += grid_[i][j-1];
25                }
26                adjSumMap_[grid_[i][j]] = adj;
27
28                int diag = 0;
29                if (i + 1 < n && j + 1 < m) {
30                    diag += grid_[i+1][j+1];
31                }
32                if (i - 1 >= 0 && j - 1 >= 0) {
33                    diag += grid_[i-1][j-1];
34                }
35                if (i + 1 < n && j - 1 >= 0) {
36                    diag += grid_[i+1][j-1];
37                }
38                if (i - 1 >= 0 && j + 1 < m) {
39                    diag += grid_[i-1][j+1];
40                }
41
42                diagSumMap_[grid_[i][j]] = diag;
43            }
44        }
45    }
46    
47    int adjacentSum(int value) {
48        return adjSumMap_[value];
49    }
50    
51    int diagonalSum(int value) {
52        return diagSumMap_[value];
53    }
54};
55
56/**
57 * Your NeighborSum object will be instantiated and called as such:
58 * NeighborSum* obj = new NeighborSum(grid);
59 * int param_1 = obj->adjacentSum(value);
60 * int param_2 = obj->diagonalSum(value);
61 */