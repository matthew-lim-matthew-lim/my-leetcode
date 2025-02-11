class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();

        for (int i = 0; i <= n - m; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (s[i + j] != part[j]) {
                    match = false;
                    break;
                }
            }
            if (match == true) {
                string newS = s.substr(0, i) + s.substr(i + m);
                return removeOccurrences(newS, part);
            }
        }

        return s;
    }
};