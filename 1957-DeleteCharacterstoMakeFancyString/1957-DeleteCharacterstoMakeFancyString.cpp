class Solution {
public:
    string makeFancyString(string s) {
        char curr_char = s[0];
        int curr_char_count = 1;

        string res;
        res += curr_char;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == curr_char) {
                curr_char_count++;
            } else {
                curr_char = s[i];
                curr_char_count = 1;
            }
            if (curr_char_count <= 2) {
                res += s[i];
            }
        }

        return res;
    }
};