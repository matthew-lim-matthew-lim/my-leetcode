// Last updated: 3/29/2026, 4:35:53 PM
1/* 
2Characters 2 digits apart must be the same in s1 and s2. 
3*/
4class Solution {
5public:
6    bool canBeEqual(string s1, string s2) {
7        int n = s1.size();
8
9        for (int i = 0; i < n; i++) {
10            if (s1[i] != s2[i]) {
11                if (i+2 >= n) {
12                    return false;
13                }
14
15                swap(s1[i], s1[i+2]);
16                if (s1[i] != s2[i]) {
17                    return false;
18                }
19            }
20        }
21
22        return true;
23    }
24};