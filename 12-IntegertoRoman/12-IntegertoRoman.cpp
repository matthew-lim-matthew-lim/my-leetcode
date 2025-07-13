// Last updated: 7/13/2025, 5:38:25 PM
class Solution {
private:
    vector<pair<int, string>> vals = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };

public:
    string intToRoman(int num) {
        // Go digit-by-digit

        string res;

        int i = vals.size() - 1;

        while (num > 0) {
            if (num - vals[i].first >= 0) {
                num -= vals[i].first;
                res += vals[i].second;
            } else {
                i--;
            }
        }

        return res;
    }
};