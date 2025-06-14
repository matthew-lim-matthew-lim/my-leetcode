// Last updated: 6/14/2025, 3:34:03 PM
/* 
You always remap the first digit.
 */

class Solution {
public:
    int minMaxDifference(int num) {
        int numCopy = num;
        int numDigits = 0;
        while (numCopy /= 10) {
            numDigits++;
        }

        int firstDigit = -1;
        int big = 0;
        int small = 0;
        for (int i = numDigits; i >= 0; i--) {
            int p = (int)pow(10, i);
            int digit = (num / p) % 10;

            if (firstDigit == -1 && digit != 9) {
                firstDigit = digit;
            }

            if (digit == firstDigit) {
                big += 9 * p;
            } else {
                big += digit * p;
            }
        }

        firstDigit = -1;
        for (int i = numDigits; i >= 0; i--) {
            int p = (int)pow(10, i);
            int digit = (num / p) % 10;

            if (firstDigit == -1 && digit != 0) {
                firstDigit = digit;
            }

            if (digit == firstDigit) {
                small += 0 * p;
            } else {
                small += digit * p;
            }
        }

        return big - small;
    }
};