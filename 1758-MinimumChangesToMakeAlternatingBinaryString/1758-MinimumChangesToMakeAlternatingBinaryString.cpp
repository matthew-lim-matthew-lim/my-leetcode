// Last updated: 3/6/2026, 12:40:33 AM
1class Solution {
2public:
3    int minOperations(string s) {
4        int evenZero = 0;
5        int oddZero = 0;
6        int n = s.size();
7        for (int i = 0; i < n; i++) {
8            if (s[i] == '0') {
9                if (i % 2 == 0) {
10                    oddZero++;
11                } else {
12                    evenZero++;
13                }
14            } else {
15                if (i % 2 == 0) {
16                    evenZero++;
17                } else {
18                    oddZero++;
19                }
20            }
21        }
22
23        return min(evenZero, oddZero);
24    }
25};