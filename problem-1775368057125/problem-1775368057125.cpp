// Last updated: 4/5/2026, 3:47:37 PM
1/* 
2Max number of special indicies:
3- ((n-1) / 2).
4
5The numbers you'd perform the operations on must be starting 
6from index 1 (the second entry in the array). 
7
8This is a greedy problem. 
9A very easy one. 
10
11Edgecase:
12- If the length of nums is odd, then you have only 1
13way to make it.
14- If the length of nums is even, then you have 2 
15ways to make it. -> This is not true.
16
17If the length of nums is even, you have make it a lot of 
18ways. You will skip one of the entries, and that can 
19be moved along the array. 
20
21Prefix sum and suffix sum will work. 
22At each index, consider you started at the 2nd digit 
23from the left side (prefix).
24Also, consider you started at the 2nd digit 
25from the right side (suffix).
26*/
27class Solution {
28public:
29    long long minIncrease(vector<int>& nums) {
30        int n = nums.size();
31
32        long long res = 0;
33
34        if (n % 2 != 0) {
35            for (int i = 1; i < n-1; i += 2) {
36                int maxNeighbour = max(nums[i-1], nums[i+1]);
37                res += max(
38                    0, 
39                    maxNeighbour - nums[i] + 1
40                );
41            }
42        } else {
43            res = LLONG_MAX;
44            vector<long long> prefix(n, 0);
45            vector<long long> suffix(n, 0);
46            
47            for (int i = 1; i < n-1; i += 2) {
48                prefix[i] += prefix[i-1];
49                
50                int maxNeighbour = max(nums[i-1], nums[i+1]);
51
52                prefix[i] += max(
53                    0, 
54                    maxNeighbour - nums[i] + 1
55                );
56
57                prefix[i+1] += prefix[i];
58            }
59
60            for (int i = n-2; i > 0; i -= 2) {
61                suffix[i] += suffix[i+1];
62                
63                int maxNeighbour = max(nums[i-1], nums[i+1]);
64                
65                suffix[i] += max(
66                    0, 
67                    maxNeighbour - nums[i] + 1
68                );
69
70                suffix[i-1] += suffix[i];
71            }
72
73            for (int i = 1; i < n-1; i++) {
74                if (i+2 < n-1) {
75                    res = min(
76                        res,
77                        prefix[i] + suffix[i+2]
78                    ); 
79                } else {
80                    res = min(
81                        res,
82                        prefix[i]
83                    );
84                }
85            }
86
87            for (int i = n-2; i > 0; i--) {
88                if (i-2 >= 0) {
89                    res = min(
90                        res,
91                        prefix[i-2] + suffix[i]
92                    ); 
93                } else {
94                    res = min(
95                        res,
96                        suffix[i]
97                    );
98                }
99            }
100
101            // for (int i = 0; i < n; i++) {
102            //     cout << prefix[i] << " " << suffix[i] << endl;
103            // }
104        }
105
106        return res;
107    }
108};