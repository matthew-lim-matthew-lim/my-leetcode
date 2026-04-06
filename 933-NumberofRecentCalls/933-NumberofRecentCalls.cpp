// Last updated: 4/7/2026, 12:36:56 AM
1/* 
2Queue.
3Simply return the queue size.
4 */
5class RecentCounter {
6public:
7    RecentCounter() {
8        
9    }
10    
11    int ping(int t) {
12        q.push(t);
13        while (!q.empty() && q.front() + 3000 < t) {
14            q.pop();
15        }
16
17        return q.size();
18    }
19
20private:
21    queue<int> q;
22};
23
24/**
25 * Your RecentCounter object will be instantiated and called as such:
26 * RecentCounter* obj = new RecentCounter();
27 * int param_1 = obj->ping(t);
28 */