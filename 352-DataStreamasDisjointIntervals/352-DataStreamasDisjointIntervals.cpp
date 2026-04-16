// Last updated: 4/16/2026, 10:45:12 PM
1class SummaryRanges {
2private:
3    vector<int> cnt;
4public:
5    SummaryRanges() : cnt(100001, 0) {
6        
7    }
8    
9    void addNum(int value) {
10        cnt[value] = 1;
11    }
12
13    vector<vector<int>> getIntervals() {
14        // iterate through
15        vector<vector<int>> ans;
16        int start = -1;
17        for (int i = 0; i < 100001; i++) {
18            if (start == -1 && cnt[i] == 1) {
19                start = i;
20            } else if (start != -1 && cnt[i] == 0) {
21                ans.push_back({start, i - 1});
22                start = -1;
23            }
24        }
25        // keep track of intervals that have consecutive cnts = 1
26        // if 0 put the current interval in the ans and keep going
27        return ans;
28    }
29};
30
31
32/**
33 * Your SummaryRanges object will be instantiated and called as such:
34 * SummaryRanges* obj = new SummaryRanges();
35 * obj->addNum(value);
36 * vector<vector<int>> param_2 = obj->getIntervals();
37 */