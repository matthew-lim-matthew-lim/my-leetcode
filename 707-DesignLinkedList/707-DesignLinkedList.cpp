// Last updated: 4/8/2026, 5:33:19 PM
1class MyLinkedList {
2public:
3    MyLinkedList() {
4        
5    }
6    
7    int get(int index) {
8        Node* curr = data_;
9        for (
10            size_t i = 0;
11            curr != nullptr;
12            curr = curr->next,
13            i++
14        ) {
15            if (i == index) {
16                return curr->value;
17            }
18        }
19
20        return -1;
21    }
22    
23    void addAtHead(int val) {
24        Node* head = new Node{
25            data_,
26            val
27        };
28
29        data_ = head;
30    }
31    
32    void addAtTail(int val) {
33        Node* curr = data_;
34        Node* prev = data_;
35
36        while (curr != nullptr) {
37            prev = curr;
38            curr = curr->next;
39        }
40
41        Node* newNode = new Node{
42            nullptr, 
43            val
44        };
45
46        if (prev != nullptr) {
47            prev->next = newNode;
48        } else {
49            data_ = newNode;
50        }
51    }
52    
53    void addAtIndex(int index, int val) {
54        if (index == 0) {
55            Node* oldHead = data_;
56            data_ = new Node{
57                oldHead,
58                val
59            };
60
61            return;
62        }
63
64        Node* curr = data_;
65        for (
66            size_t i = 0;
67            curr != nullptr;
68            curr = curr->next,
69            i++
70        ) {
71            if (i == index - 1) {
72                Node* newNode = new Node{
73                    curr->next,
74                    val
75                };
76                curr->next = newNode;
77                return;
78            }
79        }
80    }
81    
82    void deleteAtIndex(int index) {
83        if (index == 0 && data_ != nullptr) {
84            Node* newHead = data_->next;
85            delete data_;
86            data_ = newHead;
87            return;
88        }
89        
90        Node* curr = data_;
91        for (
92            size_t i = 0;
93            curr != nullptr;
94            curr = curr->next,
95            i++
96        ) {
97            if (i == index - 1) {
98                if (curr->next == nullptr) {
99                    return;
100                }
101                Node* oldNext = curr->next;
102                curr->next = curr->next->next;
103
104                delete oldNext;
105
106                return;
107            }
108        }
109    }
110
111private:
112    struct Node {
113        Node* next;
114        int value;
115    };
116
117    Node* data_ = nullptr;
118};
119
120/**
121 * Your MyLinkedList object will be instantiated and called as such:
122 * MyLinkedList* obj = new MyLinkedList();
123 * int param_1 = obj->get(index);
124 * obj->addAtHead(val);
125 * obj->addAtTail(val);
126 * obj->addAtIndex(index,val);
127 * obj->deleteAtIndex(index);
128 */