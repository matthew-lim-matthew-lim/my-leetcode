// Last updated: 4/6/2026, 12:09:10 AM
1/* 
2Interesting Allocator simulation haha. 
3
4Linked list and Free list?
5struct Node {
6    int size;
7    int index;
8};
9
10- list<Node> nodes_.
11- unordered_map<MID, vector<list<Node>::iterator> nodes_map_;
12- map<Index, list<Node>::iterator> free_list_;
13
14When adding a new node to the free_list_, check the left and right nodes
15to see if the nodes can be combined. 
16 */
17using MID = int;
18using Index = int;
19
20class Allocator {
21public:
22    Allocator(int n) : 
23        data_{Node{n, 0}}, 
24        free_list_{{0, data_.begin()}}
25    {}
26    
27    int allocate(int size, int mID) {
28        if (free_list_.empty()) {
29            return -1;
30        }
31
32        for (pair<const Index, list<Node>::iterator> p : free_list_) {
33            if (p.second->size == size) {
34                nodes_map_[mID].push_back(p.second);
35                int index = p.first;
36                free_list_.erase(index);
37                return index;
38            } else if (p.second->size > size) {
39                int index = p.first;
40                list<Node>::iterator it = data_.insert(p.second, Node{
41                    size,
42                    p.second->index
43                });
44
45                nodes_map_[mID].push_back(it);
46
47                p.second->size = p.second->size - size;
48                p.second->index = p.second->index + size;
49
50                free_list_.erase(index);
51                free_list_[p.second->index] = p.second;
52
53                return index;
54            }
55        }
56
57        return -1;
58    }
59    
60    int freeMemory(int mID) {
61        int res = 0;
62        for (list<Node>::iterator it : nodes_map_[mID]) {
63            res += it->size;
64
65            // Join the free ones
66            int index = it->index;
67            int size = it->size;
68            free_list_[index] = it;
69            auto it2 = free_list_.find(index);
70
71            if (it2 != free_list_.begin() &&
72                prev(it2)->second->index + prev(it2)->second->size == index
73            ) {
74                it2--;
75                it2->second->size += size;
76                data_.erase(next(it2)->second);
77                free_list_.erase(index);
78            }
79
80            if (next(it2) != free_list_.end() &&
81                it2->second->index + it2->second->size == next(it2)->second->index
82            ) {
83                int next_it2_index = next(it2)->second->index;
84                it2->second->size += next(it2)->second->size;
85                data_.erase(next(it2)->second);
86                free_list_.erase(next_it2_index);
87            }
88        }
89
90        nodes_map_.erase(mID);
91
92        return res;
93    }
94private:
95    struct Node {
96        int size;
97        int index;
98    };
99
100    list<Node> data_;
101    unordered_map<MID, vector<list<Node>::iterator>> nodes_map_;
102    map<Index, list<Node>::iterator> free_list_;
103};
104
105/**
106 * Your Allocator object will be instantiated and called as such:
107 * Allocator* obj = new Allocator(n);
108 * int param_1 = obj->allocate(size,mID);
109 * int param_2 = obj->freeMemory(mID);
110 */