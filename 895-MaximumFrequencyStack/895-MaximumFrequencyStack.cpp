// Last updated: 4/25/2026, 4:30:00 PM
1/* 
2map<int Freq, 
3
4For each frequency, what is the stack order?
5
6For each frequency, what element values do we consider?
7For the element values, what ones appear last. 
8
9int currIndex = 0;
10map<int Freq, set<{ int lastIndex, int element }> >;
11unordered_map<int element, { set<{ int lastIndex, int element }>::iterator, vector<int> prevIndexes } >;
12
13What are the previous positions of our elements?
14
15For an element of frequency X, what positions does it occur in?
16 */
17class FreqStack {
18private:
19    int currIndex = 0;
20
21    struct FreqElement {
22        int lastIndex;
23        int val;
24
25        bool operator<(const FreqElement& other) const {
26            if (lastIndex != other.lastIndex) {
27                return lastIndex < other.lastIndex;
28            }
29            return val < other.val; 
30        }
31    };
32    map<int, set<FreqElement>> freqMap;
33
34    struct ElementEntry {
35        set<FreqElement>::iterator iter;
36        stack<int> prevIndexes;
37    };
38    unordered_map<int, ElementEntry> elemMap;
39
40public:
41    FreqStack() {
42        
43    }
44    
45    void push(int val) {
46        int freq;
47        if (elemMap.contains(val)) {
48            freq = elemMap[val].prevIndexes.size();
49            freqMap[freq].erase(elemMap[val].iter);
50            if (freqMap[freq].empty()) {
51                freqMap.erase(freq);
52            }
53        }
54        elemMap[val].prevIndexes.push(currIndex);
55        freq = elemMap[val].prevIndexes.size();
56
57        auto [iter, success] = freqMap[freq].insert(FreqElement{
58            currIndex,
59            val
60        });
61
62        elemMap[val].iter = iter;
63
64        currIndex++;
65    }
66    
67    int pop() {
68        auto itFreq = prev(freqMap.end());
69        int newFreq = itFreq->first - 1;
70        auto itSet = prev(itFreq->second.end());
71        int res = itSet->val;
72        itFreq->second.erase(itSet);
73        if (itFreq->second.empty()) {
74            freqMap.erase(itFreq);
75        }
76
77        elemMap[res].prevIndexes.pop();
78        if (newFreq == 0) {
79            elemMap.erase(res);
80        } else {
81            int prevIndex = elemMap[res].prevIndexes.top();
82
83            auto [iter, success] = freqMap[newFreq].insert(FreqElement{
84                prevIndex,
85                res
86            });
87
88            elemMap[res].iter = iter;
89        }
90        
91        return res;
92    }
93};
94
95/**
96 * Your FreqStack object will be instantiated and called as such:
97 * FreqStack* obj = new FreqStack();
98 * obj->push(val);
99 * int param_2 = obj->pop();
100 */