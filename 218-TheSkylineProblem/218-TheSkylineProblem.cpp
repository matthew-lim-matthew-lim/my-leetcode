// Last updated: 4/11/2026, 5:21:19 PM
1/* 
2When the tallest one ends, we need to know the next tallest one. Priority queue.
3
4We keep track of the current index. 
5Add the building into the PQ if we are at the index.
6Keep popping from the PQ if the current index is bigger. 
7
8Basically, at any point in time we only care about:
9- The start indexes. 
10- The end index of the topmost building. 
11
12If the end index of the topmost building is smaller than any of the start indexes, end that building.
13If the next buildings in the pq are smaller, ignore them. 
14Then, you will have a new topmost building with an end index. 
15
16If we want to add a new silhouette marker and the previous market is the same height, then don't add it.
17
18When we are at the end, add a silhouette marker with 0 height. 
19 */
20using Height = int;
21using EndIndex = int;
22
23class Solution {
24public:
25    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
26        priority_queue<pair<Height, EndIndex>> pq;
27
28        vector<vector<int>> res;
29        res.push_back({buildings[0][0], buildings[0][2]});
30
31        /* 
32        .first = height
33        .second = endIndex
34         */
35
36        for (vector<int> building : buildings) {
37            while (!pq.empty() && pq.top().second < building[0]) {
38                pair<int, int> oldTop = pq.top();
39                pq.pop();
40                while (!pq.empty() && pq.top().second <= oldTop.second) {
41                    pq.pop();
42                }
43                pair<int, int> newTop = pq.empty() ? pair<int, int>(0, oldTop.second) : pq.top();
44                if (oldTop.second < building[1] && oldTop.second > res.back()[0]) {
45                    res.push_back({oldTop.second, newTop.first});
46                }
47            } 
48
49            if (building[2] > res.back()[1]) {
50                if (res.back()[0] == building[0]) {
51                    res.back()[1] = building[2];
52                } else {
53                    res.push_back({building[0], building[2]});
54                }
55            }
56
57            pq.push({building[2], building[1]});
58        }
59
60        while (!pq.empty()) {
61            pair<int, int> oldTop = pq.top();
62            pq.pop();
63            while (!pq.empty() && pq.top().second <= oldTop.second) {
64                pq.pop();
65            }
66            pair<int, int> newTop = pq.empty() ? pair<int, int>(0, oldTop.second) : pq.top();
67            if (oldTop.second > res.back()[0]) {
68                res.push_back({oldTop.second, newTop.first});
69            }
70        } 
71
72        return res;
73    }
74};