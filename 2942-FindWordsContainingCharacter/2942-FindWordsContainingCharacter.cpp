// Last updated: 5/24/2025, 1:17:51 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                res.emplace_back(i);
            }
        }

        return res;
    }
};