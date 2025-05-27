// Last updated: 5/27/2025, 7:08:20 PM
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                res -= i;
            } else {
                res += i;
            }
        }

        return res;
    }
};