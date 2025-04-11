// Last updated: 4/11/2025, 12:30:48 PM
class Solution {
public:
    bool symmetric(int num) {
        // Get size of this number. 
        int curr = num;
        int numDigits = 0;
        while (curr > 0) {
            curr /= 10;
            numDigits++;
        }

        // If odd, false
        if (numDigits % 2 == 1) {
            return false;
        }

        // Now, find if first half sum is same as last half sum.
        int firstHalfSum = 0;
        int lastHalfSum = 0;

        curr = num;
        for (int i = 0; i < numDigits/2; i++) {
            lastHalfSum += (curr / (int)pow(10, i)) % 10;
        }

        for (int i = 0; i < numDigits/2; i++) {
            firstHalfSum += (curr / (int)pow(10, numDigits - i - 1)) % 10;
        }

        return lastHalfSum == firstHalfSum;
    }

    int countSymmetricIntegers(int low, int high) {
        // Get the sum of the first half and the sum of the second half.
        // Must have even number of digits. 
        int res = 0;
    
        for (int val = low; val <= high; val++) {
            res += symmetric(val);
        }

        return res;
    }
};