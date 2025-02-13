class StreamChecker {
private:
    vector<string> words_;
    string bigWord;
public:
    StreamChecker(vector<string>& words) {
        words_ = words;
    }
    
    bool query(char letter) {
        // Query builds a string. Check if any suffix of that string is in words.
        bigWord += letter;

        for (string& word : words_) {
            // Go backwards from each word to see if it works.
            if (word.size() > bigWord.size()) {
                continue;
            }
            bool match = true;
            for (int i = 0; i < word.size(); i++) {
                if (word[(word.size() - 1) - i] != bigWord[(bigWord.size() - 1) - i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
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