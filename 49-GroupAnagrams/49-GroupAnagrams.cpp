// Last updated: 5/27/2025, 7:20:17 PM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Can't have sets with mutable stuff as the key.
        unordered_map<string, vector<string>> m;

        for (string &s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            m[copy].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &p : m) {
            vector<string> currAna;
            for (auto &entry : p.second) {
                currAna.emplace_back(entry);
            }
            res.emplace_back(currAna);
        }

        return res;
    }
};