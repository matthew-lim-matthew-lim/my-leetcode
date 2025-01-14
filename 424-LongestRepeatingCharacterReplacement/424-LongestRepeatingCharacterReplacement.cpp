#include <algorithm>

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Probably use a map to keep track of each character in the sliding window, and keep track of the length of the sliding window.
        // This tells us how may we needed to replace (length - char_map[i]).
        // The best way would be to use the highest count character as the one that is attempted to be repeated.
        // We can just find the highest count character at each step since there are only 26 characters. 
        // Time complexity should be O(n).

        int res = 1;
        vector<int> char_map(26, 0);
        int l_ptr = 0;
        for (int r_ptr = 0; r_ptr < s.size(); r_ptr++) {
            char_map[s[r_ptr] - 'A']++;
            int highest_count = *max_element(char_map.begin(), char_map.end());
            // cout << (r_ptr - l_ptr + 1) << " " << highest_count + k << endl;
            if (!((r_ptr - l_ptr + 1) > highest_count + k)) {
                res = max(res, r_ptr - l_ptr + 1);
            }
            while ((r_ptr - l_ptr + 1) > highest_count + k) {
                char_map[s[l_ptr] - 'A']--;
                l_ptr++;
            }
        }

        return res;
    }
};