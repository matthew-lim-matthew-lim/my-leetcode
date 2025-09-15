// Last updated: 9/15/2025, 6:10:44 PM
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;

        unordered_set<char> brokenSet;
        for (char &c : brokenLetters) {
            brokenSet.insert(c);
        }

        text += ' ';
        bool valid = true;
        for (char &c : text) {
            if (brokenSet.contains(c)) {
                valid = false;
            }
            if (c == ' ') {
                res += valid;
                valid = true;
            }
        }

        return res;
    }
};