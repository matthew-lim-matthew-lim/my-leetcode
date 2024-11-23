class Solution {
public:
    void backtrack(
        unordered_map<char, string> char_map,
        string& digits,
        vector<string>& res,
        string& curr,
        int curr_index
    ) {
        if (curr.size() == digits.size()) {
            if (curr.size() > 0) res.push_back(curr);
            return;
        }

        // Now, iterate through the possible next letters
        for (int i = 0; i < char_map[digits[curr_index]].size(); i++) {
            curr.push_back(char_map[digits[curr_index]][i]);
            backtrack(char_map, digits, res, curr, curr_index + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> char_map {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> res;
        string curr = "";

        backtrack(char_map, digits, res, curr, 0);

        return res;
    }
};