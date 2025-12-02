// Last updated: 12/2/2025, 11:56:15 PM
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
13    void backtrack(string &currString, int currOpens, int currCloses) {
14        if (currOpens < maxOpens) {
15            currString += "(";
16            backtrack(currString, currOpens + 1, currCloses);
17            currString.pop_back();
18        }
19        if (currCloses < currOpens) {
20            currString += ")";
21            backtrack(currString, currOpens, currCloses + 1);
22            currString.pop_back();
23        }
24        if (currOpens == maxOpens && currOpens == currCloses) {
25            res.push_back(currString);
26        }
27    }
28
29    vector<string> generateParenthesis(int n) {
30        maxOpens = n;
31
32        string curr;
33        backtrack(curr, 0, 0);
34
35        return res;
36    }
37};