// Last updated: 4/24/2026, 8:13:11 PM
1class SeatManager {
2private:
3    priority_queue<int, vector<int>, greater<>> pq;
4public:
5    SeatManager(int n) {
6        for (int i = 1; i <= n; i++) {
7            pq.push(i);
8        }
9    }
10    
11    int reserve() {
12        int next = pq.top();
13        pq.pop();
14
15        return next;
16    }
17    
18    void unreserve(int seatNumber) {
19        pq.push(seatNumber);
20    }
21};
22
23/**
24 * Your SeatManager object will be instantiated and called as such:
25 * SeatManager* obj = new SeatManager(n);
26 * int param_1 = obj->reserve();
27 * obj->unreserve(seatNumber);
28 */