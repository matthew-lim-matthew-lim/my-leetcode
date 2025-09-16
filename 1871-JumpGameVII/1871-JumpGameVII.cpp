// Last updated: 9/16/2025, 2:58:39 PM
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> valid(n, 0);

        int currValid = 0;
        for (int i = 0; i < n; i++) {
            currValid += valid[i];
            if (s[i] == '0' && (i == 0 || currValid >= 1)) {
                if (i + minJump < n) {
                    valid[i + minJump]++;
                }
                if (i + maxJump + 1 < n) {
                    valid[i + maxJump + 1]--;
                }
            }
            while (i < minJump - 1) {
                i++;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << valid[i] << " ";
        // }

        return s[n - 1] == '0' && currValid >= 1;
    }
};