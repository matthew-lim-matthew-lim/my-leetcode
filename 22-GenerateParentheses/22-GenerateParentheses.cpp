// Last updated: 12/2/2025, 11:54:41 PM
1/* 
2Backtracking.
3
4At each one, you can open and close. 
5Keep track of number of opens, as number of closes must never exceed number of opens.
6Number of opens also must never exceed n.
7 */
8class Solution {
9public:
10    int maxOpens;
11    vector<string> res;
12
13    void backtrack(string currString, int currOpens, int currCloses) {
14        if (currOpens < maxOpens) {
15            backtrack(currString + "(", currOpens + 1, currCloses);
16        }
17        if (currCloses < currOpens) {
18            backtrack(currString + ")", currOpens, currCloses + 1);
19        }
20        if (currOpens == maxOpens && currOpens == currCloses) {
21            res.push_back(currString);
22        }
23    }
24
25    vector<string> generateParenthesis(int n) {
26        maxOpens = n;
27
28        backtrack("", 0, 0);
29
30        return res;
31    }
32};