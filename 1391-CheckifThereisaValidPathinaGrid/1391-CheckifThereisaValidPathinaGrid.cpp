// Last updated: 4/27/2026, 12:27:33 PM
1/* 
2Isn't this easy?
3
4- Keep track of direction.
5- Check if the adjacent tile supports that direction.
6- Move in that direction. 
7
8We should not use a queue, since there is only one path. 
9
10- If the current direction is not supported by that tile, then there is no valid path.
11- If the current position is out of bounds, then there is no valid path. 
12
13Eg. 
14- Street 2: Up and down: {1, 0} -> {1, 0}
15- Street 4: Up and right: {1, 0} -> {0, 1}
16- Street 4: Up and right: {0, -1} -> {-1, 0}
17 */
18class Solution {
19private:
20    struct pair_hash {
21        size_t operator()(const std::pair<int, int>& p) const {
22            // A common way to combine hash values for a pair
23            return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
24        }
25    };
26
27    vector<unordered_map<pair<int, int>, pair<int, int>, pair_hash>> directions{
28        {{{-1, -1}, {-1, -1}}},
29        {{{0, 1}, {0, 1}}, {{0, -1}, {0, -1}}},
30        {{{-1, 0}, {-1, 0}}, {{1, 0}, {1, 0}}},
31        {{{0, 1}, {1, 0}}, {{-1, 0}, {0, -1}}},
32        {{{-1, 0}, {0, 1}}, {{0, -1}, {1, 0}}},
33        {{{0, 1}, {-1, 0}}, {{1, 0}, {0, -1}}},
34        {{{1, 0}, {0, 1}}, {{0, -1}, {-1, 0}}},
35    };
36
37public:
38    bool hasValidPath(vector<vector<int>>& grid) {
39        int n = grid.size();
40        int m = grid[0].size();
41
42        if (n==1 && m==1) {
43            return true;
44        }
45
46        for (const auto p : directions[grid[0][0]]) {
47            vector<vector<bool>> visited(n, vector<bool>(m, false));
48            visited[0][0] = true;
49
50            pair<int, int> curr = {0, 0};
51            pair<int, int> currDirection = {-1, -1};
52            if (curr.first + p.second.first >= 0 && curr.second + p.second.second >= 0) {
53                currDirection.first = p.second.first;
54                currDirection.second = p.second.second;
55
56                curr.first += currDirection.first;
57                curr.second += currDirection.second;
58                
59                // cout << curr.first << " " << curr.second << endl;
60                // cout << "dir: " << currDirection.first << " " << currDirection.second << endl;
61
62                while (curr.first >= 0 && 
63                    curr.first < n &&
64                    curr.second >= 0 &&
65                    curr.second < m
66                ) {
67                    if (visited[curr.first][curr.second]) {
68                        // Cycle
69                        break;
70                    }
71
72                    visited[curr.first][curr.second] = true;
73                    if (directions[grid[curr.first][curr.second]].contains(currDirection)) {
74                        currDirection = directions[grid[curr.first][curr.second]][currDirection];
75                    } else {
76                        break;
77                    }
78
79                    if (curr.first == n-1 &&
80                        curr.second == m-1
81                    ) {
82                        return true;
83                    }
84
85                    curr.first += currDirection.first;
86                    curr.second += currDirection.second;
87
88                    // cout << curr.first << " " << curr.second << endl;
89                }
90            }
91        }
92
93        return false;
94    }
95};