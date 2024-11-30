class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Check first and last
        if (sentence[0] != sentence[sentence.size() - 1]) {
            return false;
        }

        // Check letters on either side of spaces.
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};