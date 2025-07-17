// Last updated: 7/18/2025, 2:01:15 AM
/* 
Trie?
 */
class WordDictionary {
private:

struct Node  {
    bool end = false;
    unordered_map<char, Node*> outgoing;
};

    Node* root;

public:
    WordDictionary() {
        root = new Node;   
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->outgoing.contains(c)) {
                curr->outgoing[c] = new Node;
            }
            curr = curr->outgoing[c];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        queue<pair<Node*, int>> q;
        q.push({ root, 0 });
        while (!q.empty()) {
            pair<Node*, int> curr = q.front();
            q.pop();

            if (curr.second == word.size() && curr.first->end) {
                return true;
            }

            if (word[curr.second] == '.') {
                for (pair<char, Node*> p : curr.first->outgoing) {
                    q.push({ p.second, curr.second + 1 });
                }
            } else if (curr.first->outgoing.contains(word[curr.second])) {
                q.push({ curr.first->outgoing[word[curr.second]], curr.second + 1 });
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