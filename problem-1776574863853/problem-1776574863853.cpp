// Last updated: 4/19/2026, 3:01:03 PM
1/*
2Digit DP. 
3We can't possibly go through all of the numbers from l to r as that time complexity is too high. 
4Digits not in the path dont count, we dont care about them.
5
6digitDp(r) - digitDp(l);
7*/
8class Solution {
9private:
10    long long memo[16][2][10]; // [idx][tight][last_digit]
11    string S;
12
13    bool in_path[16];
14public:
15
16    long long dp(int idx, bool tight, int last_path_digit) {
17        if (idx == S.size()) return 1;
18    
19        if (memo[idx][tight][last_path_digit] != -1)
20            return memo[idx][tight][last_path_digit];
21    
22        long long ans = 0;
23        int limit = tight ? (S[idx] - '0') : 9;
24        
25        for (int d = 0; d <= limit; ++d) {
26            bool next_tight = tight && (d == limit);
27            
28            if (in_path[idx]) {
29                if (d >= last_path_digit) {
30                    ans += dp(idx + 1, next_tight, d); 
31                }
32            } else {
33                ans += dp(idx + 1, next_tight, last_path_digit); 
34            }
35        }
36    
37        return memo[idx][tight][last_path_digit] = ans;
38    }
39
40    long long solve(long long n) {
41        if (n < 0) return 0;
42        S = to_string(n);
43        if (S.size() < 16) {
44            S.insert(0, 16 - S.size(), '0');
45        }
46        memset(memo, -1, sizeof(memo));
47        return dp(0, true, 0);
48    }
49
50    void createPath(string directions) {
51        int y = 0;
52        int x = 0;
53        long long res = 0;
54        for (char c : directions) {
55            in_path[y * 4 + x] = true;
56            if (c == 'D') {
57                y++;
58            } else if (c == 'R') {
59                x++;
60            }
61        }
62        in_path[y * 4 + x] = true;
63    }
64    
65    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
66        createPath(directions);
67        
68        return solve(r) - solve(l-1);
69    }
70};