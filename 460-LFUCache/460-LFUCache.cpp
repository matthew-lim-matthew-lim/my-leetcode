// Last updated: 4/16/2026, 2:01:34 AM
1using Key = int;
2using Value = int;
3
4class LFUCache {
5public:
6    LFUCache(int capacity) : remCapacity_(capacity) {}
7    
8    void update(int key, int value, int useCount) {
9        if (entryMap_.contains(key)) {
10            useMap_[useCount].erase(entryMap_[key]);
11            if (useMap_[useCount].empty()) {
12                useMap_.erase(useCount);
13            }
14        }
15
16        useMap_[useCount + 1].push_back(Entry{
17            key, 
18            value, 
19            useCount + 1
20        });
21
22        entryMap_[key] = prev(useMap_[useCount + 1].end());
23    }
24
25    int get(int key) {
26        if (!entryMap_.contains(key)) {
27            return -1;
28        }
29        
30        Entry oldEntry = *entryMap_[key];
31
32        update(oldEntry.key, oldEntry.value, oldEntry.useCount);
33
34        return oldEntry.value;
35    }
36    
37    void put(int key, int value) {
38        int useCount = 0;
39        if (!entryMap_.contains(key)) {
40            remCapacity_--;
41        } else {
42            useCount = entryMap_[key]->useCount;
43        }
44
45        if (remCapacity_ < 0) {
46            remCapacity_++;
47
48            list<Entry>::iterator it = useMap_.begin()->second.begin();
49            entryMap_.erase(it->key);
50            useMap_.begin()->second.erase(it);
51            if (useMap_.begin()->second.empty()) {
52                useMap_.erase(useMap_.begin());
53            }
54        }
55
56        update(key, value, useCount);
57    }
58private:
59    struct Entry {
60        int key;
61        int value;
62        int useCount;
63    };
64
65    map<int, list<Entry>> useMap_;
66    unordered_map<Key, list<Entry>::iterator> entryMap_;
67    int remCapacity_;
68};
69
70/**
71 * Your LFUCache object will be instantiated and called as such:
72 * LFUCache* obj = new LFUCache(capacity);
73 * int param_1 = obj->get(key);
74 * obj->put(key,value);
75 */