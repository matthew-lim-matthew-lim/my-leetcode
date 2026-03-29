// Last updated: 3/29/2026, 7:59:00 PM
1/* 
2Can convert a window of '0' with a '1' into a complete section of '1'. 
3
400111001
5
6We can convert 2 blocks of 1s into 1 block of 1s. 
7*/
8class Solution {
9public:
10    int maxActiveSectionsAfterTrade(string s) {
11        int baseLine = 0;
12        int n = s.size();
13
14        int blockCount = 0;
15
16        for (int i = 0; i < n; i++) {
17            if (s[i] == '1') {
18                baseLine++;
19            }
20        }
21
22        int res = baseLine;
23
24        int r = 0;
25        int currCount = 0;
26        for (; r < n; r++) {
27            if (s[r] == '0') {
28                break;
29            } else {
30                currCount++;
31            }
32        }
33
34        int l = 0;
35        for (; r < n; r++) {
36            if (s[r] == '1') {
37                // cout << r << endl;
38                currCount++;
39            }
40            if (r > 0 && s[r] == '0' && s[r-1] == '1') {
41                blockCount++;
42            }
43            while (blockCount > 2) {
44                if (l < n && s[l] == '1') {
45                    currCount--;
46                }
47                l++;
48                if (l < n && s[l] == '0' && s[l-1] == '1') {
49                    blockCount--;
50                }
51                if (l >= n) {
52                    break;
53                }
54            }
55            if (blockCount == 1) {
56                // cout << "YOYO" << endl;
57                int next0 = l;
58                int thisCurr = currCount;
59                bool breakAction = false;
60                while (next0 < n && s[next0] == '1') {
61                    thisCurr--;
62                    next0++;
63                    if (s[next0] == '0' && s[next0-1] == '1') {
64                        breakAction = true;
65                    }
66                }
67                if (breakAction) {
68                    continue;
69                }
70                if (next0 == n || next0 >= r) {
71                    continue;
72                }
73                // cout << "GRRR " << next0 << " " << r << endl;
74                res = max(res, r - next0 + 1 + baseLine - thisCurr);
75            } else if (blockCount == 2) {
76                while (s[l] == '0') {
77                    l++;
78                }
79                // cout << r << " " << l << " " << currCount << " " << baseLine << endl;
80                res = max(res, r - l + 1 + baseLine - currCount);
81            }
82        }
83
84        return res;
85    }
86};