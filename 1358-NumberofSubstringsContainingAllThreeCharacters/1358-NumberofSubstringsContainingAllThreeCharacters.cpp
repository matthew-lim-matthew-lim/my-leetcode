class Solution {
public:
    bool valid(unordered_map<char, int>& charCount) {
        if (charCount['a'] == 0 ||
            charCount['b'] == 0 || 
            charCount['c'] == 0
        ) {
            return false;
        }
        return true;
    }

    int numberOfSubstrings(string s) {
        // Whenever we have a valid substring, all the substrings that contain the letters before and after are also valid. 
        // At each index, get the last occurence of a/b/c altogether, using precomputation.
        // Add the count from that index to then. 
        int res = 0;
        int n = s.size();
        int l_ptr = 0;
        unordered_map<char, int> charCount = {{'a', 0}, {'b', 0}, {'c', 0}};
        for (int r_ptr = 0; r_ptr < n; r_ptr++) {
            charCount[s[r_ptr]]++;
            while (valid(charCount)) {
                res += (n - r_ptr);
                charCount[s[l_ptr]]--;
                l_ptr++;
            }
        }

        return res;
    }
};