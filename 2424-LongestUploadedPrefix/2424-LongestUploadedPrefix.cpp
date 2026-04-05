// Last updated: 4/5/2026, 10:51:15 PM
1/* 
2- LL
3Can do it with a LL. 
4When we add a new entry, we pop the corresponding LL node.
5The longest() query checks the front. If the front node is numbered 'x', 
6then the longest prefix is 'x-1'. 
7
8- O(1) longest() query
9- O(1) upload() query
10It works, but way slower than vector due to poor cache locality.
11
12- Vector
13Can do it with a vector. 
14When we add a new entry, we put it in the vector.
15If the current entry pointed to by the vector is used, bump the pointer.
16The longest() query returns `pointer`. 
17
18The vector solution is better. 
19- O(1) longest() query. 
20- O(n) upload() query, when the user uploads something, it might cause the pointer
21to move rightwards up to `n` times. 
22 */
23class LUPrefix {
24public:
25    LUPrefix(int n) {
26        for (int i = 0; i <= n; i++) {
27            data_.push_back(i);
28            data_map_[i+1] = prev(data_.end());
29        }
30    }
31    
32    void upload(int video) {
33        data_.erase(data_map_[video]);
34        data_map_.erase(video);
35    }
36    
37    int longest() {
38        return data_.front();
39    }
40private:
41    list<int> data_;
42    unordered_map<int, list<int>::iterator> data_map_;
43};
44
45/**
46 * Your LUPrefix object will be instantiated and called as such:
47 * LUPrefix* obj = new LUPrefix(n);
48 * obj->upload(video);
49 * int param_2 = obj->longest();
50 */