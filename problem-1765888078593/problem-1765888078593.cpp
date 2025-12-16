// Last updated: 12/16/2025, 11:27:58 PM
1/*
2- (distance between index) * (value at index).
3- THERE IS ONLY 1 NEGATIVE STARTING BALANCE!!!
4- Simply use an r and l pointer.
5*/
6class Solution {
7public:
8    long long minMoves(vector<int>& balance) {
9        if ((long long)accumulate(balance.begin(), balance.end(), 0LL) < 0LL) {
10            return -1;
11        }
12
13        int n = balance.size();
14        int target = 0;
15        for (int i = 0; i < n; i++) {
16            if (balance[i] < 0) {
17                target = i;
18            }
19        }
20
21        long long res = 0;
22        for (int i = 1; i < n && balance[target] < 0; i++) {
23            int l = (n + target - i) % n;
24            int r = (n + target + i) % n;
25
26            long long move = (long long)min(-balance[target], balance[l]);
27            res += move * i;
28            balance[target] += move;
29            if (balance[target] >= 0) {
30                return res;
31            }
32            move = (long long)min(-balance[target], balance[r]);
33            res += move * i;
34            balance[target] += move;
35        }
36
37        return res;
38    }
39};