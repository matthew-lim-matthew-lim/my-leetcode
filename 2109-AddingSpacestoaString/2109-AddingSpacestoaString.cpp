class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newstr;
        int spaces_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (spaces_index < spaces.size() && spaces[spaces_index] == i) {
                newstr += " ";
                spaces_index++;
            } 
            newstr += s[i];
        }

        return newstr;
    }
};