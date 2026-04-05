// Last updated: 4/5/2026, 2:05:59 PM
1/*
2Count the frequency of each character.
3Compute the mirror pairs of only the characters in the first half of each.
4*/
5class Solution {
6public:
7    int mirrorFrequency(string s) {
8        unordered_map<char, int> charCount;
9
10        unordered_set<char> charSet;
11
12        for (char c : s) {
13            charCount[c]++;
14
15            if ('a' <= c && c <= 'm') {
16                charSet.insert(c);
17            } else if ('m' < c && c <= 'z') {
18                charSet.insert(char('z' - (c - 'a')));
19            }
20
21            if ('0' <= c && c <= '4') {
22                charSet.insert(c);
23            } else if ('4' < c && c <= '9') {
24                charSet.insert(char('9' - (c - '0')));
25            }
26        }
27
28        int res = 0;
29        
30        for (char c : charSet) {
31            if ('a' <= c && c <= 'm') {
32                res += abs(charCount[c] - charCount['z' - (c - 'a')]);
33            }
34
35            if ('0' <= c && c <= '4') {
36                res += abs(charCount[c] - charCount['9' - (c - '0')]);
37            }
38        }
39
40        return res;
41    }
42};