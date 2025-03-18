class Solution {
public:
    bool canPermutePalindrome(string s) {
        // One character odd, other characters even.
        vector<bool> charCount(26, false);
        for (char c : s) {
            charCount[c - 'a'] = !charCount[c - 'a'];
        }

        int oddCount = 0;
        for (bool b : charCount) {
            if (b == true) {
                oddCount++;
            }
        }

        return oddCount <= 1;
    }
};