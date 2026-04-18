// Last updated: 4/19/2026, 12:11:41 AM
1class Solution {
2public:
3    int mirrorDistance(int n) {
4        int ogNum = n;
5        int revNum = 0;
6        while (n > 0) {
7            revNum *= 10;
8            revNum += (n % 10);
9            n /= 10;
10        }
11
12        return abs(ogNum - revNum);
13    }
14};