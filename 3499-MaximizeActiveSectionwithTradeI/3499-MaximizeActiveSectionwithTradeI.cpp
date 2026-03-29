// Last updated: 3/29/2026, 7:59:30 PM
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
37                currCount++;
38            }
39            if (r > 0 && s[r] == '0' && s[r-1] == '1') {
40                blockCount++;
41            }
42            while (blockCount > 2) {
43                if (l < n && s[l] == '1') {
44                    currCount--;
45                }
46                l++;
47                if (l < n && s[l] == '0' && s[l-1] == '1') {
48                    blockCount--;
49                }
50                if (l >= n) {
51                    break;
52                }
53            }
54            if (blockCount == 1) {
55                int next0 = l;
56                int thisCurr = currCount;
57                bool breakAction = false;
58                while (next0 < n && s[next0] == '1') {
59                    thisCurr--;
60                    next0++;
61                    if (s[next0] == '0' && s[next0-1] == '1') {
62                        breakAction = true;
63                    }
64                }
65                if (breakAction) {
66                    continue;
67                }
68                res = max(res, r - next0 + 1 + baseLine - thisCurr);
69            } else if (blockCount == 2) {
70                while (s[l] == '0') {
71                    l++;
72                }
73                res = max(res, r - l + 1 + baseLine - currCount);
74            }
75        }
76
77        return res;
78    }
79};