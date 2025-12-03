// Last updated: 12/3/2025, 11:04:15 PM
1/* 
2Split into substrings, so all chars must be used. 
3
4Isn't this legit just the number of unique characters there are? 
5
6Just do unique chars, and for every following character that is non-unique, include it in the substring. 
7*/
8class Solution {
9public:
10    int maxDistinct(string s) {
11        unordered_set<char> cSet;
12
13        for (char c : s) {
14            cSet.insert(c);
15        }
16
17        return cSet.size();
18    }
19};