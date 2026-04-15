// Last updated: 4/15/2026, 11:42:03 PM
1class SummaryRanges {
2public:
3    SummaryRanges() {
4        
5    }
6    
7    /* 
8    Combine the next element as necessary.
9    Combine the previous element as necessary. 
10     */
11    void addNum(int value) {
12        auto it = pList_.upper_bound({value, value});
13
14        if (it != pList_.end() && 
15            (*it)[0] <= value
16        ) {
17            return;
18        }
19
20        if (it != pList_.begin() && 
21            (*prev(it))[1] >= value
22        ) {
23            return;
24        }
25
26        bool combineNext = false;
27        if (it != pList_.end() && (*it)[0] == value + 1) {
28            combineNext = true;
29        }
30
31        bool combinePrev = false;
32        if (it != pList_.begin() && (*prev(it))[1] == value - 1) {
33            combinePrev = true;
34        }
35
36        if (combineNext && combinePrev) {
37            vector<int> newEntry{0, 0};
38
39            newEntry[1] = (*it)[1];
40            newEntry[0] = (*prev(it))[0];
41            
42            pList_.erase(prev(it));
43            pList_.erase(it);
44
45            pList_.insert(newEntry);
46        } else if (combineNext) {
47            vector<int> newEntry{0, 0};
48
49            newEntry[1] = (*it)[1];
50            newEntry[0] = value;
51            
52            pList_.erase(it);
53
54            pList_.insert(newEntry);
55        } else if (combinePrev) {
56            vector<int> newEntry{0, 0};
57
58            newEntry[1] = value;
59            newEntry[0] = (*prev(it))[0];
60            
61            pList_.erase(prev(it));
62
63            pList_.insert(newEntry);
64        } else {
65            vector<int> newEntry{value, value};
66            pList_.insert(newEntry);
67        }
68    }
69    
70    vector<vector<int>> getIntervals() {
71        return {pList_.begin(), pList_.end()};
72    }
73private:
74    set<vector<int>> pList_;
75};
76
77/**
78 * Your SummaryRanges object will be instantiated and called as such:
79 * SummaryRanges* obj = new SummaryRanges();
80 * obj->addNum(value);
81 * vector<vector<int>> param_2 = obj->getIntervals();
82 */