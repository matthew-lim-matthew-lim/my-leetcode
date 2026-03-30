// Last updated: 3/31/2026, 10:14:05 AM
1/* 
2See if you can match all the odd indicies.
3See if you can match all the even indicies.
4*/
5class Solution {
6public:
7    bool checkStrings(string s1, string s2) {
8        vector<int> charCountOdd(26, 0);
9        vector<int> charCountEven(26, 0);
10
11        int n = s1.size();
12
13        for (int i = 0; i < n; i++) {
14            if (i % 2 == 0) {
15                charCountEven[s1[i] - 'a']++;
16                charCountEven[s2[i] - 'a']--;
17            } else {
18                charCountOdd[s1[i] - 'a']++;
19                charCountOdd[s2[i] - 'a']--;
20            }
21        }
22
23        for (int i = 0; i < 26; i++) {
24            if (charCountOdd[i] != 0) {
25                return false;
26            }
27            if (charCountEven[i] != 0) {
28                return false;
29            }
30        }
31
32        return true;
33    }
34};