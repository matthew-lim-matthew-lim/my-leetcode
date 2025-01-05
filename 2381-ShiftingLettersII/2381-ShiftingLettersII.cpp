class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // If we iterate through s for each shift: O(n * k) (where 'k' is the number of shifts).
        
        // This is more efficient using a difference array.
        // At 'shifts[0]', add 'shifts[2]'.
        // At 'shifts[1] + 1', subtract 'shifts[2]'.

        vector<int> diff(s.size() + 1, 0);

        for (vector<int>& shift : shifts) {
            if (shift[2] == 0) {
                diff[shift[0]]--;
                diff[shift[1] + 1]++;
            } else {
                diff[shift[0]]++;
                diff[shift[1] + 1]--;
            }
        }

        int curr_diff = 0;
        // Use the difference array to compute the array.
        for (int i = 0; i < s.size(); i++) {
            curr_diff += diff[i] % 26;

            s[i] = ((((s[i] - 'a') + curr_diff) % 26) + 26) % 26 + 'a';
            cout << curr_diff << endl;
        }

        return s;
    }
};