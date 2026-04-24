// Last updated: 4/24/2026, 11:27:56 AM
1/* 
2Trie
3 */
4struct Trie {
5    unordered_map<char, shared_ptr<Trie>> tMap;
6    int val = 0;
7};
8
9class MapSum {
10private:
11    shared_ptr<Trie> trie;
12public:
13    MapSum() {
14        trie = make_shared<Trie>();
15    }
16    
17    void insert(string key, int val) {
18        shared_ptr<Trie> triePtr = trie;
19
20        int n = key.size();
21
22        for (int i = 0; i < n; i++) {
23            if (triePtr->tMap.contains(key[i])) {
24                triePtr = triePtr->tMap[key[i]];
25            } else {
26                triePtr->tMap[key[i]] = make_shared<Trie>();
27                triePtr = triePtr->tMap[key[i]];
28            }
29        }
30
31        triePtr->val = val;
32    }
33    
34    /* 
35    Nagivate through the prefix, and then BFS from there.
36     */
37    int sum(string prefix) {
38        shared_ptr<Trie> triePtr = trie;
39
40        int res = 0;
41        int n = prefix.size();
42
43        for (int i = 0; i < n; i++) {
44            if (triePtr->tMap.contains(prefix[i])) {
45                triePtr = triePtr->tMap[prefix[i]];
46            } else {
47                return res;
48            }
49        }
50
51        queue<shared_ptr<Trie>> q;
52        q.push(triePtr);
53
54        while (!q.empty()) {
55            triePtr = q.front();
56            res += triePtr->val;
57            q.pop();
58            for (auto p : triePtr->tMap) {
59                q.push(p.second);
60            }
61        }
62
63        return res;
64    }
65};
66
67/**
68 * Your MapSum object will be instantiated and called as such:
69 * MapSum* obj = new MapSum();
70 * obj->insert(key,val);
71 * int param_2 = obj->sum(prefix);
72 */