class Solution {
public:
    int trailingZeroes(int n) {
        int num2 = 0;
        int num5 = 0;

        for (int i = 1; i <= n; i++) {
            int curr;
            if ((i / 2) * 2 == i) {
                curr = i;
                while (curr % 2 == 0) {
                    num2++;
                    curr /= 2;
                }
            }
            if ((i / 5) * 5 == i) {
                curr = i;
                while (curr % 5 == 0) {
                    num5++;
                    curr /= 5;
                }
            }
        }

        return min(num2, num5);
    }
};