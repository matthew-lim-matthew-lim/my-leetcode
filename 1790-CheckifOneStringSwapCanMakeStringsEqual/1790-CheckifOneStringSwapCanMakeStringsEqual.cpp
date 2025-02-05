class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // Just check if there are exactly 2 different characters.
        unordered_set<char> diffChars;
        int diffCharCount = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffChars.insert(s2[i]);
                diffCharCount++;
            }
        }

        if (diffCharCount == 0) return true;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (!diffChars.contains(s1[i])) return false;
            }
        }

        return diffCharCount == 2;
    }
};