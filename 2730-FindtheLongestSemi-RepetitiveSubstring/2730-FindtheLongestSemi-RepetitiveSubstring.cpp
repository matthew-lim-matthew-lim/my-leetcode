// Last updated: 3/29/2026, 5:54:00 PM
1/*
2If there is a second semi-adjacent pair, move the l_ptr. 
3*/
4class Solution {
5public:
6    int longestSemiRepetitiveSubstring(string s) {
7        int n = s.size();
8        if (n == 1) {
9            return n;
10        }
11        int r_ptr = 1;
12        while (r_ptr < n && s[r_ptr] != s[r_ptr-1]) {
13            r_ptr++;
14        }
15        if (s[r_ptr] != s[r_ptr-1]) {
16            return r_ptr;
17        }
18
19        int res = r_ptr + 1;
20        r_ptr++;
21        int l_ptr = 0;
22        // At this stage, there 1 semi-repetitive inside r_ptr and s_ptr;
23        for (; r_ptr < n; r_ptr++) {
24            if (s[r_ptr] == s[r_ptr-1]) {
25                do {
26                    l_ptr++;
27                } while (s[l_ptr] != s[l_ptr-1]);
28            }
29            res = max(res, r_ptr - l_ptr + 1);
30        }
31
32        return res;
33    }
34};