class Solution {
public:
    string getHappyString(int n, int k) {
        // The number of strings you can make is `3 * 2^(n - 1)`.
        // For the first character, there are `2^(n - 1)` different strings.
        // For the second character, there are `2^(n - 2)` different strings.

        int currLen = 3 * pow(2, n - 1);
        int nextLen = currLen;
        int nextK = k - 1;

        if (k > currLen) {
            return "";
        }
        string res;

        vector<char> letters = { 'a', 'b', 'c' };

        while (res.size() < n) {
            if (res.size() == 0) {
                nextLen /= 3;
            } else {
                nextLen /= 2;
            }
            int nextIndex = nextK / nextLen;
            nextK = nextK % nextLen;
            int nextCharIndex = -1;
            while (nextIndex >= 0) {
                nextCharIndex++;
                nextIndex--;
                if (!res.empty() && res.back() == letters[nextCharIndex]) {
                    nextCharIndex++;
                }
            }
            res += letters[nextCharIndex];
        }

        return res;
    }
};