// Last updated: 3/31/2026, 10:07:48 AM
1/* 
2See if you can match all the odd indicies.
3See if you can match all the even indicies.
4*/
5class Solution {
6public:
7    bool checkStrings(string s1, string s2) {
8        multiset<char> oddS1;
9        multiset<char> oddS2;
10        multiset<char> evenS1;
11        multiset<char> evenS2;
12
13        int n = s1.size();
14
15        for (int i = 0; i < n; i++) {
16            if (i % 2 == 0) {
17                evenS1.insert(s1[i]);
18                evenS2.insert(s2[i]);
19            } else {
20                oddS1.insert(s1[i]);
21                oddS2.insert(s2[i]);
22            }
23        }
24
25        return evenS1 == evenS2 && oddS1 == oddS2;
26    }
27};