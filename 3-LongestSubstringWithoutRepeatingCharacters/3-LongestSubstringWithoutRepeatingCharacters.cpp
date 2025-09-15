// Last updated: 9/16/2025, 2:02:22 AM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cSet;
        int res = 0;
        int l = 0;
        for (int i = 0; i < s.size(); i++) {
            while (cSet.contains(s[i])) {
                cSet.erase(s[l]);
                l++;
            }
            cSet.insert(s[i]);
            res = max(res, i - l + 1);
        }

        return res;
    }
};