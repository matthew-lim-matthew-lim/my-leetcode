// Last updated: 3/1/2026, 1:34:31 PM
1class Solution {
2public:
3    bool isVowel(char c) {
4        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
5    }
6    
7    string trimTrailingVowels(string s) {
8        int n = s.size();
9
10        for (int i = n-1; i >= 0; i--) {
11            if (!isVowel(s[i])) {
12                return s.substr(0, i+1);
13            }
14        }
15
16        return "";
17    }
18};