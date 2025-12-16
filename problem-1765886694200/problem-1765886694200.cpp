// Last updated: 12/16/2025, 11:04:54 PM
1class Solution {
2public:
3    bool isVowel(char c) {
4        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
5    }
6    
7    string reverseWords(string s) {
8        int n = s.size();
9        string res;
10        string currWord;
11        int targetVowels = 0;
12        int i = 0;
13        while (i < n && s[i] != ' ') {
14            currWord += s[i];
15            targetVowels += isVowel(s[i]);
16            i++;
17        }
18        res += currWord;
19        currWord = "";
20        i++;
21        if (i >= n) {
22            return res;
23        }
24
25        int currVowels = 0;
26        for (; i < n; i++) {
27            char c = s[i];
28
29            if (c == ' ') {
30                if (currVowels == targetVowels) {
31                    reverse(currWord.begin(), currWord.end());
32                }
33                res += " " + currWord;
34                currWord = "";
35                currVowels = 0;
36            } else {
37                currVowels += isVowel(c);
38                currWord += c;
39            }
40        }
41
42        if (currVowels == targetVowels) {
43            reverse(currWord.begin(), currWord.end());
44        }
45        res += " " + currWord;
46
47        return res;
48    }
49};