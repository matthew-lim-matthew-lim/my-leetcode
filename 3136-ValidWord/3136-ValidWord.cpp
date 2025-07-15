// Last updated: 7/15/2025, 8:44:17 PM
class Solution {
public:
    bool isValid(string word) {
        bool vowelFound = false;
        bool consonantFound = false;

        if (word.size() < 3) {
            return false;
        }

        for (char c : word) {
            c = tolower(c);
            if (!((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0'))) {
                return false;
            }
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelFound = true;
            } else if (!(c <= '9' && c >= '0')) {
                consonantFound = true;
            }
        }

        return vowelFound && consonantFound;
    }
};