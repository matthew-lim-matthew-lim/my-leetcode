class Solution {
public:
    bool canConstruct(string s, int k) {
        // Note that we just have to use the characters in 's', so its not a substring problem. 
        // Each odd number of characters needs to be in its own palindrome. 
        vector<int> char_map(26, 0);
        for (char& c : s) {
            char_map[c - 'a']++;
        }

        // k >= odd_char_count.
        // k <= total_char_count. 

        int odd_char_count = 0;
        int total_char_count = 0;
        for (int i = 0; i < char_map.size(); ++i) {
            if (char_map[i] % 2 == 1) odd_char_count++;
            total_char_count += char_map[i];
        }

        return k >= odd_char_count && k <= total_char_count;
    }
};