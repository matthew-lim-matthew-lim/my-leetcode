// Last updated: 3/29/2026, 1:52:17 PM
1/* 
2Solve with two multisets.
3
4upper and lower.
5The back() of lower should be smaller than the front() of upper. 
6
7When you delete a value, compare it to the back() of lower, and the front() of upper, 
8this will tell you which side to delete from.
9
10When you add a value, compare it to the back() of lower, and the front() of upper, 
11add it to the corresponding one. 
12
13If it is even number, and lower.size() > upper.size(),
14move the back of lower into upper.
15If lower.size() < upper.size(),
16move the start of upper into lower. 
17
18If it is odd, and lower.size() > upper.size() + 1,
19move the back of lower into upper. 
20If lower.size() < upper.size() + 1,
21move the front of upper into lower. 
22*/
23class Solution {
24public:
25    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
26        if (k == 1) {
27            return vector<double>{nums.begin(), nums.end()};
28        }
29
30        bool even = k % 2 == 0;
31        int n = nums.size();
32        multiset<int> upper;
33        multiset<int> lower;
34
35        vector<double> res;
36
37        for (int i = 0; i < k; i++) {
38            lower.insert(nums[i]);
39        }
40
41        while (
42            (even && lower.size() > upper.size()) ||
43            (!even && lower.size() > upper.size() + 1)
44        ) {
45            upper.insert(*prev(lower.end()));
46            lower.erase(prev(lower.end()));
47        }
48
49        if (even) {
50            res.push_back(((long long)*upper.begin() + (long long)*prev(lower.end())) / 2.0);
51        } else {
52            res.push_back(*prev(lower.end()));
53        }
54
55        for (int i = k; i < n; i++) {
56            // cout << i << endl;
57            int newNum = nums[i];
58            if (newNum <= *prev(lower.end())) {
59                lower.insert(newNum);
60            } else {
61                upper.insert(newNum);
62            }
63
64            int toDelete = nums[i - k];
65            // cout << "deleting: " << toDelete << endl;
66            // for (int j : lower) {
67            //     cout << "lower: " << j << " ";
68            // }
69            // for (int j : upper) {
70            //     cout << "upper: " << j << " ";
71            // }
72            // cout << endl;
73            if (toDelete <= *prev(lower.end())) {
74                auto it = lower.find(toDelete);
75                lower.erase(it);
76            } else {
77                auto it = upper.find(toDelete);
78                upper.erase(it);
79            }
80
81            while (
82                (even && lower.size() > upper.size()) ||
83                (!even && lower.size() > upper.size() + 1)
84            ) {
85                upper.insert(*prev(lower.end()));
86                lower.erase(prev(lower.end()));
87            }
88            while (
89                (even && lower.size() < upper.size()) ||
90                (!even && lower.size() < upper.size() + 1)
91            ) {
92                lower.insert(*upper.begin());
93                upper.erase(upper.begin());
94            }
95
96            if (even) {
97                res.push_back(((long long)*upper.begin() + (long long)*prev(lower.end())) / 2.0);
98            } else {
99                res.push_back(*prev(lower.end()));
100            }
101        }
102
103        return res;    
104    }
105};