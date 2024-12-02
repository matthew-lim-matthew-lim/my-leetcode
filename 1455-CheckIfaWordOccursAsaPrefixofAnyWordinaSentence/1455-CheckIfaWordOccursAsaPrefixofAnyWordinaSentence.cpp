class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string curr_word;

        int curr_word_i = 0;
        int curr_word_num = 0;

        while (ss >> curr_word) {
            curr_word_i = 0;
            curr_word_num++;
            while (curr_word_i < searchWord.size() && curr_word[curr_word_i] == searchWord[curr_word_i]) {
                curr_word_i++;
            }
            if (curr_word_i == searchWord.size()) {
                return curr_word_num;
            }
        }
        
        return -1;
    }
};