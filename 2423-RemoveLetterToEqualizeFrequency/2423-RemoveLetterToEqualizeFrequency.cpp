class Solution {
public:
    bool equalFrequency(string word) {
        // Brute force is O(n) since only 26 different characters

        // Count the number of characters with a different frequency.
        unordered_map<char, int> freq;

        for (char c : word) {
            freq[c]++;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (!freq.contains(c)) {
                continue;
            }

            freq[c]--;

            // Check if valid
            int expected_count = INT_MAX;
            bool found = true;
            for (pair<char, int> char_int : freq) {
                if (char_int.second == 0) {
                    continue;
                }
                if (expected_count == INT_MAX) {
                    expected_count = char_int.second;
                }
                if (char_int.second != 0 && char_int.second != expected_count) {
                    found = false;
                }
            }
            if (found == true) {
                return true;
            }

            freq[c]++;
        }

        return false;
    }
};