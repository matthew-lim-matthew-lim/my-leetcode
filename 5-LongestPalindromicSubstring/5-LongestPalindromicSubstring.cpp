// Last updated: 4/9/2025, 1:24:08 PM
class Solution {
public:
    string longestPalindrome(string s) {
        // For each one, measure how long it can extend left and right. 
        // For each i, extend left and right. Keep track of the largest plaindrome found so far.
        int n = s.size();
        string res;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
            }
            l++;
            r--;
            if (r - l + 1 > res.size()) {
                res = s.substr(l, r - l + 1);
            }
            // Even length palindrome
            if (i + 1 < n && s[i] == s[i + 1]) {
                int l = i - 1;
                int r = i + 2;
                while (l >= 0 && r < n) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l--;
                    r++;
                }
                l++;
                r--;
                if (r - l + 1 > res.size()) {
                    res = s.substr(l, r - l + 1);
                }
            }
        }

        return res;
    }
};