class Solution {
public:
    long long coloredCells(int n) {
        // Math and DP
        long long res = 1;
        for (int i = 2; i <= n; i++) {
            res += 4 * (i - 1);
        }
        return res;
    }
};