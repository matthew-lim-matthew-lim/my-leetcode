// Last updated: 3/31/2026, 10:14:40 AM
class Solution {
public:
    bool checkStrings(const string& s1, const string& s2) {
        int even[26] = {0}, odd[26] = {0};

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (even[i] != 0 || odd[i] != 0) {
                return false;
            }
        }

        return true;
    }
};