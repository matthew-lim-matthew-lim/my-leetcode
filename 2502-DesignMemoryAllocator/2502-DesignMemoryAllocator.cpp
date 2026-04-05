// Last updated: 4/6/2026, 12:58:43 AM
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
23        free_list_{{0, Node{n, 0}}}
24    {}
25    
26    int allocate(int size, int mID) {
27        if (free_list_.empty()) {
28            return -1;
29        }
30
31        for (pair<const Index, Node> p : free_list_) {
32            if (p.second.size == size) {
33                nodes_map_[mID].push_back(p.second);
34                int index = p.first;
35                free_list_.erase(index);
36                return index;
37            } else if (p.second.size > size) {
38                int index = p.first;
39
40                nodes_map_[mID].push_back(Node{
41                    size,
42                    index
43                });
44
45                p.second.size = p.second.size - size;
46                p.second.index = p.second.index + size;
47
48                free_list_.erase(index);
49                free_list_[p.second.index] = p.second;
50
51                return index;
52            }
53        }
54
55        return -1;
56    }
57    
58    int freeMemory(int mID) {
59        int res = 0;
60        for (Node it : nodes_map_[mID]) {
61            res += it.size;
62
63            // Join the free ones
64            int index = it.index;
65            int size = it.size;
66            free_list_[index] = it;
67            auto it2 = free_list_.find(index);
68
69            if (it2 != free_list_.begin() &&
70                prev(it2)->second.index + prev(it2)->second.size == index
71            ) {
72                it2--;
73                it2->second.size += size;
74                free_list_.erase(index);
75            }
76
77            if (next(it2) != free_list_.end() &&
78                it2->second.index + it2->second.size == next(it2)->second.index
79            ) {
80                int next_it2_index = next(it2)->second.index;
81                it2->second.size += next(it2)->second.size;
82                free_list_.erase(next_it2_index);
83            }
84        }
85
86        nodes_map_.erase(mID);
87
88        return res;
89    }
90private:
91    struct Node {
92        int size;
93        int index;
94    };
95
96    unordered_map<MID, vector<Node>> nodes_map_;
97    map<Index, Node> free_list_;
98};
99
100/**
101 * Your Allocator object will be instantiated and called as such:
102 * Allocator* obj = new Allocator(n);
103 * int param_1 = obj->allocate(size,mID);
104 * int param_2 = obj->freeMemory(mID);
105 */