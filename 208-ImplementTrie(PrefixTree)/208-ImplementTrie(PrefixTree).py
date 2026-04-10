# Last updated: 4/10/2026, 7:16:33 PM
1""" 
2Dict to Dicts 
3
4Node {
5    dict chars;
6    bool end;
7}
8
9"""
10class Trie:
11    class Node:
12        def __init__(self):
13            self.neigh: dict = {}
14            self.end: bool = False
15
16    def __init__(self):
17        self.root = self.Node()
18
19    def insert(self, word: str) -> None:
20        def insert_recurse(curr_node: Node, rem_word: str):
21            if (len(rem_word) == 0):
22                curr_node.end = True
23                return
24
25            if rem_word[0] not in curr_node.neigh:
26                curr_node.neigh[rem_word[0]] = self.Node()
27            insert_recurse(curr_node.neigh[rem_word[0]], rem_word[1:])
28        
29        if word[0] not in self.root.neigh:
30            self.root.neigh[word[0]] = self.Node()
31
32        insert_recurse(self.root.neigh[word[0]], word[1:])
33
34    def search(self, word: str) -> bool:
35        def search_recurse(curr_node: Node, rem_word: str):
36            if len(rem_word) == 0:
37                if curr_node.end:
38                    return True
39                else:
40                    return False
41            
42            if rem_word[0] in curr_node.neigh:
43                return search_recurse(curr_node.neigh[rem_word[0]], rem_word[1:])
44            else:
45                return False
46        
47        if word[0] in self.root.neigh:
48            return search_recurse(self.root.neigh[word[0]], word[1:])
49        else:
50            return False
51
52    def startsWith(self, prefix: str) -> bool:
53        def starts_recurse(curr_node: Node, rem_word: str):
54            if len(rem_word) == 0:
55                return True
56            
57            if rem_word[0] in curr_node.neigh:
58                return starts_recurse(curr_node.neigh[rem_word[0]], rem_word[1:])
59            else:
60                return False
61        
62        if prefix[0] in self.root.neigh:
63            return starts_recurse(self.root.neigh[prefix[0]], prefix[1:])
64        else:
65            return False
66
67
68# Your Trie object will be instantiated and called as such:
69# obj = Trie()
70# obj.insert(word)
71# param_2 = obj.search(word)
72# param_3 = obj.startsWith(prefix)