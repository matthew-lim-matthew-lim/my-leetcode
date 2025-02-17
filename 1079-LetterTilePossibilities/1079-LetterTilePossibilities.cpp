class Solution {
public:
    void backtrack(unordered_map<char, int> chars, string currString, unordered_set<string>& res) {
        for (pair<char, int> c : chars) {
            string newString = currString + c.first;
            if (c.second > 0 && !res.contains(newString)) {
                res.insert(newString);
                chars[c.first]--;
                backtrack(chars, newString, res);
                chars[c.first]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        // Backtracking using a set?
        unordered_set<string> res;
        unordered_map<char, int> chars;
        for (char c : tiles) {
            chars[c]++;
        }
        backtrack(chars, "", res);
        return res.size();
    }
};