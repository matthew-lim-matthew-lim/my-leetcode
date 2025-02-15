class Solution {
public:
    bool valid(string s, int target) {
        if (target == 0) {
            if (s.size() == 0 || stoi(s) == 0) {
                return true;
            } else {
                return false;
            }
        } else if (target < 0) {
            return false;
        }
        // Use backtracking
        for (int j = 1; j <= s.size(); j++) {
            // cout << "target " << target << endl;
            // cout << "using " << s.substr(0, j) << " leaving " << s.substr(j) << endl;
            int newTarget = target - stoi(s.substr(0, j));
            // cout << "new target " << newTarget << endl;
            if (valid(s.substr(j), newTarget)) return true;
        }

        // cout << "didn't work" << endl;

        return false;
    }

    int punishmentNumber(int n) {
        // 1 is a punishment number
        int res = 1;
        for (int i = 2; i <= n; i++) {
            int iSquared = i * i;
            if (valid(to_string(iSquared), i)) {
                res += i * i;
            }
        }

        return res;
    }
};