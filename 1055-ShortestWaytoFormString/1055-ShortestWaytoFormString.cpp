// Last updated: 3/30/2025, 12:41:32 PM
class Solution {
public:
    int shortestWay(string source, string target) {
        // O(mn)
        // 1 pointer for target.
        // 1 pointer for source. 
        unordered_set<char> sourceChars(source.begin(), source.end());

        int substringCount = 0;
        int sourcePtr = 0;
        for (char c : target) {
            if (!sourceChars.contains(c)) {
                return -1;
            }
            // We have a pointer for source that for each time we reset, we increment a count.
            while (source[sourcePtr] != c) {
                sourcePtr++;
                if (sourcePtr == source.size()) {
                    substringCount++;
                    sourcePtr = 0;
                }
            }
            sourcePtr++;
            if (sourcePtr == source.size()) {
                substringCount++;
                sourcePtr = 0;
            }
        }
        if (sourcePtr != 0) {
            substringCount++;
        }

        return substringCount;
    }
};