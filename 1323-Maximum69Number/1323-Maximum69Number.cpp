// Last updated: 8/17/2025, 2:10:49 AM
/* 
This is really easy because you would never turn a 9 into a 6. Just turn the first 6 into a 9.
 */

class Solution {
public:
    int maximum69Number (int num) {
        int n = 0;
        int numCpy = num;
        while (numCpy > 0) {
            numCpy /= 10;
            n++;
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = num / pow(10, i);
            digit %= 10;

            if (digit == 6) {
                num += pow(10, i) * 3;
                return num;
            }
        }

        return num;
    }
};