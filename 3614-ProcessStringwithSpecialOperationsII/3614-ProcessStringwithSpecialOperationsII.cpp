// Last updated: 7/16/2025, 9:43:18 PM
/* 
Maybe use a deque?

Everytime you duplicate ('#'), you compress it into a node. 
You only decompress to access that node. 
*/

class Solution {
public:
    char processStr(string s, long long k) {
        bool forwards = true;

        long long length = 0;

        for (char c : s) {
            if (c <= 'z' && c >= 'a') {
                length++;
            } 
            if (c == '#') {
                length *= 2;
            }
            if (c == '*' && length > 0) {
                length--;
            }
        }

        // Now, go through it in reverse

        if (k >= length) {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            // if (length == 0) {
            //     return '.';
            // }
            
            if (c <= 'z' && c >= 'a') {
                length--;
                if (length == k) {
                    return c;
                }
            } 
            if (c == '#') {
                length /= 2;
                k %= length;
            }
            if (c == '%') {
                k = (length - 1) - k;
            }
            if (c == '*') {
                length++;
            }
        }

        return '.';
    }
};