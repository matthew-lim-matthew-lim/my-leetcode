// Last updated: 4/5/2026, 10:43:29 PM
1/* 
2- LL
3Can do it with a LL. 
4When we add a new entry, we put it in the LL node. 
5If the LL node from the front is used up, then we can pop it from the
6front. 
7The longest() query checks the front. If the front node is numbered 'x', 
8then the longest prefix is 'x-1'. 
9
10- Vector
11Can do it with a vector. 
12When we add a new entry, we put it in the vector.
13If the current entry pointed to by the vector is used, bump the pointer.
14The longest() query returns `pointer`. 
15
16The vector solution is better. 
17- O(1) longest() query. 
18- O(n) upload() query, when the user uploads something, it might cause the pointer
19to move rightwards up to `n` times. 
20 */
21class LUPrefix {
22public:
23    LUPrefix(int n) : data_(n, false), pointer_(0) {}
24    
25    void upload(int video) {
26        data_[video-1] = true;
27        while (pointer_ < data_.size() && data_[pointer_]) {
28            pointer_++;
29        }
30    }
31    
32    int longest() {
33        return pointer_;
34    }
35private:
36    vector<bool> data_; 
37    int pointer_;
38};
39
40/**
41 * Your LUPrefix object will be instantiated and called as such:
42 * LUPrefix* obj = new LUPrefix(n);
43 * obj->upload(video);
44 * int param_2 = obj->longest();
45 */