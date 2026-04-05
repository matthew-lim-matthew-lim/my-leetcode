// Last updated: 4/5/2026, 10:50:53 PM
1/* 
2- LL
3Can do it with a LL. 
4When we add a new entry, we pop the corresponding LL node.
5The longest() query checks the front. If the front node is numbered 'x', 
6then the longest prefix is 'x-1'. 
7
8- O(1) longest() query
9- O(1) upload() query
10
11- Vector
12Can do it with a vector. 
13When we add a new entry, we put it in the vector.
14If the current entry pointed to by the vector is used, bump the pointer.
15The longest() query returns `pointer`. 
16
17The vector solution is better. 
18- O(1) longest() query. 
19- O(n) upload() query, when the user uploads something, it might cause the pointer
20to move rightwards up to `n` times. 
21 */
22class LUPrefix {
23public:
24    LUPrefix(int n) {
25        for (int i = 0; i <= n; i++) {
26            data_.push_back(i);
27            data_map_[i+1] = prev(data_.end());
28        }
29    }
30    
31    void upload(int video) {
32        data_.erase(data_map_[video]);
33        data_map_.erase(video);
34    }
35    
36    int longest() {
37        return data_.front();
38    }
39private:
40    list<int> data_;
41    unordered_map<int, list<int>::iterator> data_map_;
42};
43
44/**
45 * Your LUPrefix object will be instantiated and called as such:
46 * LUPrefix* obj = new LUPrefix(n);
47 * obj->upload(video);
48 * int param_2 = obj->longest();
49 */