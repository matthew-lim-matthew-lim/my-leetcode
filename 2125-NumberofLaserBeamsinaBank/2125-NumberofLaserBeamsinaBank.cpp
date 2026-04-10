// Last updated: 4/10/2026, 9:32:17 PM
1/* 
2Math?
3Number of devices in curr row,
4times number of devices in prev row
5 */
6class Solution {
7public:
8    int countBeams(string& row) {
9        int res = 0;
10        for (char c : row) {
11            if (c == '1') {
12                res++;
13            }
14        }
15
16        return res;
17    }
18
19    int numberOfBeams(vector<string>& bank) {
20        int res = 0;
21
22        int prev = countBeams(bank[0]);
23
24        for (int i = 1; i < bank.size(); i++) {
25            int curr = countBeams(bank[i]);
26            if (curr == 0) {
27                continue;
28            }
29
30            res += prev * curr;
31
32            prev = curr;
33        }
34
35        return res;
36    }
37};