// Last updated: 3/15/2026, 1:59:02 PM
1class Solution {
2public:
3    int countCommas(int n) {
4        return n >= 1000 ? n - 999 : 0;
5    }
6};