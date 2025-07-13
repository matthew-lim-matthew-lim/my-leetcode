// Last updated: 7/13/2025, 7:25:53 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> used;

        int res = 0;

        int l_ptr = 0;
        for (int r_ptr = 0; r_ptr < s.size(); r_ptr++) {
            while (used.contains(s[r_ptr])) {
                used.erase(s[l_ptr]);
                l_ptr++;
            }
            used.insert(s[r_ptr]);

            res = max(res, r_ptr - l_ptr + 1);
        }

        return res;
    }
};