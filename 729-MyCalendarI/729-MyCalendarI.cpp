// Last updated: 4/25/2026, 2:20:50 PM
1/* 
2Use a set.
3 */
4class MyCalendar {
5private:
6    set<vector<int>> times;
7public:
8    MyCalendar() {
9        
10    }
11    
12    bool book(int startTime, int endTime) {
13        auto it = times.lower_bound({endTime, 0});
14
15        if (it == times.begin()) {
16            times.insert({startTime, endTime - startTime});
17        } else {
18            if ((*prev(it))[0] + (*prev(it))[1] <= startTime) {
19                times.insert({startTime, endTime - startTime});
20            } else {
21                return false;
22            }
23        }
24
25        return true;
26    }
27};
28
29/**
30 * Your MyCalendar object will be instantiated and called as such:
31 * MyCalendar* obj = new MyCalendar();
32 * bool param_1 = obj->book(startTime,endTime);
33 */