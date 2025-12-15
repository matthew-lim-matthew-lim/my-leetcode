// Last updated: 12/15/2025, 11:39:46 PM
1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        int n = prices.size();
5        int l = 0;
6        long long res = 0;
7        for (int r = 0; r < n; r++) {
8            if (prices[l] - prices[r] != r - l) {
9                long long length = r - l;
10                res += (length * (length + 1)) / 2;
11                // cout << length << endl;
12                l = r;
13            }
14        }
15        long long length = n - l;
16        // cout << length << endl;
17        res += (length * (length + 1)) / 2;
18
19        return res;
20    }
21};