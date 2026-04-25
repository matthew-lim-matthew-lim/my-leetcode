// Last updated: 4/25/2026, 10:26:38 PM
1class Solution {
2private:
3    vector<string> cols;
4    vector<vector<int>> dfsCache;
5public:
6    int dfs(int n, int i) {
7        if (dfsCache[n][i] != -1) {
8            return dfsCache[n][i];
9        }
10        if (n == 0) {
11            return 1;
12        }
13        int res = 0;
14
15        for (int j = 0; j < cols.size(); j++) {
16            bool valid = true;
17
18            for (int k = 0; k < cols[0].size(); k++) {
19                if (cols[i][k] == cols[j][k]) {
20                    valid = false;
21                    break;
22                }
23            }
24
25            if (valid) {
26                res += (dfs(n-1, j) % 1'000'000'007);
27                res %= 1'000'000'007;
28            }
29        }
30
31        return dfsCache[n][i] = res;
32    }
33
34    void backtrack(string s, int m) {
35        if (s.size() == m) {
36            cols.push_back(s);
37            // cout << s << endl;
38            return;
39        }
40
41        for (char c : {'R', 'B', 'G'}) {
42            if (s.empty() || s.back() != c) {
43                backtrack(s + c, m);
44            }
45        }
46    }
47
48    int colorTheGrid(int m, int n) {
49        backtrack("", m);
50
51        dfsCache = vector<vector<int>>(n+1, vector<int>(cols.size(), -1));
52
53        int res = 0;
54
55        for (int j = 0; j < cols.size(); j++) {
56            res += dfs(n-1, j) % 1'000'000'007;
57            res %= 1'000'000'007;
58        }
59
60        return res;
61    }
62};