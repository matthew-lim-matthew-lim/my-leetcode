// Last updated: 4/18/2025, 12:38:22 PM
class Solution {
public:
    string countAndSay(int n) {
        string currStr = "1";
        string newStr;
        for (int i = 1; i < n; i++) {
            newStr = "";

            int m = currStr.size();
            char prev = currStr.front();
            unordered_map<char, int> digitCount;
            for (int j = 0; j < m; j++) {
                if (currStr[j] != prev) {
                    newStr += to_string(digitCount[prev]) + prev;
                    digitCount.erase(prev);
                    prev = currStr[j];
                }
                digitCount[currStr[j]]++;
            }
            newStr += to_string(digitCount[prev]) + prev;
            digitCount.erase(prev);

            currStr = newStr;
        }

        return currStr;
    }
};