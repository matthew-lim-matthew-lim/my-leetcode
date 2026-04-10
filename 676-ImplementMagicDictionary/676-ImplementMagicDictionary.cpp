// Last updated: 4/10/2026, 9:19:32 PM
1/* 
2Trie?
3 */
4class MagicDictionary {
5public:
6    struct Node {
7        unordered_map<char, unique_ptr<Node>> neigh;
8        bool end = false;
9    };
10
11    MagicDictionary() {
12        
13    }
14    
15    void buildDict(vector<string> dictionary) {
16        for (string s : dictionary) {
17            Node* curr = root.get();
18
19            for (char c : s) {
20                if (!curr->neigh.contains(c)) {
21                    curr->neigh[c] = make_unique<Node>();
22                }
23                curr = curr->neigh[c].get();
24            }
25            curr->end = true;
26        }
27    }
28    
29    bool recurse(string& word, int index, Node* curr, bool usedWildcard) {
30        if (index == word.size() &&
31            usedWildcard &&
32            curr->end
33        ) {
34            return true;
35        } 
36        bool result = false;
37        if (curr->neigh.contains(word[index])) {
38            result |= recurse(word, index+1, curr->neigh[word[index]].get(), usedWildcard);
39        } 
40        if (!usedWildcard) {
41            for (const auto& p : curr->neigh) {
42                if (p.first != word[index]) {
43                    result |= recurse(word, index+1, p.second.get(), true);
44                }
45            }
46        }
47        return result;
48    }
49
50    bool search(string searchWord) {
51        return recurse(searchWord, 0, root.get(), false);
52    }
53private:
54    unique_ptr<Node> root = make_unique<Node>();
55};
56
57/**
58 * Your MagicDictionary object will be instantiated and called as such:
59 * MagicDictionary* obj = new MagicDictionary();
60 * obj->buildDict(dictionary);
61 * bool param_2 = obj->search(searchWord);
62 */