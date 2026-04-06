// Last updated: 4/6/2026, 11:14:41 PM
1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int y = 0;
5        int x = 0;
6        for (char c : moves) {
7            if (c == 'U') {
8                y++;
9            } else if (c == 'D') {
10                y--;
11            } else if (c == 'R') {
12                x++;
13            } else if (c == 'L') {
14                x--;
15            }
16        }
17
18        return y==0 && x==0;
19    }
20};