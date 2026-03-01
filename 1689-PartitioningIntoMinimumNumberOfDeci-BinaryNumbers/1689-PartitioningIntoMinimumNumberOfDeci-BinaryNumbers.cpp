// Last updated: 3/1/2026, 11:51:46 AM
1/* 
2Is it genuinely not just the biggest digit? 
3 */
4class Solution {
5public:
6    int minPartitions(string n) {
7        int res = 0;
8        for (char c : n) {
9            res = max(res, c - '0');
10        }
11
12        return res;
13    }
14};