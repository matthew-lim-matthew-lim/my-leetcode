// Last updated: 9/17/2025, 10:47:11 PM
/* 
Trie asf
 */
class WordDictionary {
private:

struct Node {
    char val;
    unordered_map<char, Node*> neigh;
    bool word;
};

unordered_map<char, Node*> trie;

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* curr = nullptr;
        if (!trie.contains(word[0])) {
            trie[word[0]] = new Node(word[0], {}, false);
        }
        curr = trie[word[0]];
        for (int i = 1; i < word.size(); i++) {
            if (!curr->neigh.contains(word[i])) {
                curr->neigh[word[i]] = new Node(word[0], {}, false);
            }
            curr = curr->neigh[word[i]];
        }

        curr->word = true;
    }
    
    bool search(string word) {
        // BFS
        queue<pair<Node*, int>> q;
        if (word[0] == '.') {
            for (pair<const char, Node*> p : trie) {
                q.push({p.second, 1});
            }
        } else if (trie.contains(word[0])) {
            q.push({trie[word[0]], 1});
        }

        while (!q.empty()) {
            pair<Node*, int> curr = q.front();
            q.pop();

            if (curr.second == word.size() && curr.first->word == true) {
                return true;
            } 

            for (pair<const char, Node*> p : curr.first->neigh) {
                if (p.first == word[curr.second] || word[curr.second] == '.') {
                    q.push({p.second, curr.second + 1});
                }
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */