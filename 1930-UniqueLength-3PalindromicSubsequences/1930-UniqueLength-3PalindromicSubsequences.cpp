class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Hash table keeps track of character (key) and count (value) up to an index.
        // Prefix hash table from the left, up to but not including index 'i'. 
        // Prefix hash table from the left , up to but not including index 'i'.
        // Match the characters from the left and right hash tables.
        // Use a set to avoid double count of the new palindromic subsequences.

        unordered_set<string> res;

        unordered_map<char, int> hash_right;
        // Only count up to the 2nd character (inclusive).
        for (int i = s.size() - 1; i >= 1; --i) {
            hash_right[s[i]]++;
        }

        unordered_map<char, int> hash_left;

        // Now, go from 'i == 1' to 'i == s.size() - 2', where 'i' is the 2nd character.
        for (int i = 1; i < s.size() - 1; ++i) {
            // Modifying the prefix sums
            hash_left[s[i - 1]]++;
            hash_right[s[i]]--;
            if (hash_right[s[i]] == 0) {
                hash_right.erase(s[i]);
            }

            // Add to the res set if applicable.
            for (pair<char, int> char_int : hash_left) {
                if (hash_right.contains(char_int.first)) {
                    string new_string = string(1, char_int.first) + s[i] + string(1, char_int.first);
                    res.insert(new_string);
                }
            }
        }

        return res.size();
    }
};