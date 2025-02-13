// Basically, do BFS using a trie.

class TrieNode {
public:
    unordered_map<char, TrieNode*> tMap;
    bool word = false;
};

class StreamChecker {
private:
    TrieNode* root = new TrieNode();
    string bigWord;
public:
    StreamChecker(vector<string>& words) {
        // Build the trie.
        TrieNode* curr;
        for (string& word : words) {
            curr = root;
            for (int i = word.size() - 1; i >= 0; --i) {
                if (!curr->tMap.contains(word[i])) {
                    curr->tMap[word[i]] = new TrieNode({}, false);
                }
                curr = curr->tMap[word[i]];
                if (i == 0) {
                    curr->word = true;
                }
            }
        }
    }
    
    bool query(char letter) {
        bigWord += letter;

        // Explore the trie
        TrieNode* curr = root;
        for (int i = bigWord.size() - 1; i >= 0; --i) {
            if (!curr->tMap.contains(bigWord[i])) {
                return false;
            }
            curr = curr->tMap[bigWord[i]];
            if (curr->word == true) {
                return true;
            } 
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */