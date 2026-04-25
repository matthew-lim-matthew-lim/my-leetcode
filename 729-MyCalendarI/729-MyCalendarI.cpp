// Last updated: 4/25/2026, 2:21:25 PM
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
17            return true;
18        } else if ((*prev(it))[0] + (*prev(it))[1] <= startTime) {
19            times.insert({startTime, endTime - startTime});
20            return true;
21        }
22
23        return false;
24    }
25};
26
27/**
28 * Your MyCalendar object will be instantiated and called as such:
29 * MyCalendar* obj = new MyCalendar();
30 * bool param_1 = obj->book(startTime,endTime);
31 */