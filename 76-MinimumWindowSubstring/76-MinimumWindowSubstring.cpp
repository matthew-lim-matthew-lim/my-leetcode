class Solution {
public:
    bool valid(unordered_map<char, int>& char_map) {
        for (pair<char, int> p : char_map) {
            if (p.second > 0) {
                cout << "false" << endl;
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        // Use a hash table to keep track of counts. 
        // Move/iterate the right pointer to include stuff in the hash table. 
        // While the hash table satisfies 't', move the left pointer to exclude stuff. 
        int smallest_left = 0;
        int smallest_right = s.size();
        unordered_map<char, int> char_map;
        for (char c : t) {
            char_map[c]++;
        }

        int l_ptr = 0;
        for (int r_ptr = 0; r_ptr < s.size(); r_ptr++) {
            if (char_map.find(s[r_ptr]) != char_map.end()) {
                char_map[s[r_ptr]]--;
            }

            while (valid(char_map) && l_ptr < r_ptr) {
                if (r_ptr - l_ptr < smallest_right - smallest_left) {
                    smallest_right = r_ptr;
                    smallest_left = l_ptr;
                }

                if (char_map.find(s[l_ptr]) != char_map.end()) {
                    char_map[s[l_ptr]]++;
                }
                l_ptr++;
            }
            if (valid(char_map)) {
                if (r_ptr - l_ptr < smallest_right - smallest_left) {
                    cout << r_ptr << " " << l_ptr << endl;
                    smallest_right = r_ptr;
                    smallest_left = l_ptr;
                } 
            }
        }

        if (smallest_right != s.size()) {
            return s.substr(smallest_left, smallest_right - smallest_left + 1);
        } else {
            return "";
        }
    }
};