// Last updated: 7/10/2025, 4:45:12 PM
class Solution {
public:
    int maximumSwap(int num) {
        // When processing each digit, keep track of the largest digit and the index of that number. 

        // Keep track of the latest index of the digit that was smaller than the largest digit. 

        int largestDigit = 0;
        int largestDigitIndex = 0;

        // Keep track of small index to swap. 
        int latestSmallerDigit = 0;
        int latestSmallerDigitIndex = 0;

        int numClone = num;
        int index = 0;
        while (numClone > 0) {
            int digit = numClone % 10;

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            if (digit < largestDigit) {
                latestSmallerDigitIndex = index;
                latestSmallerDigit = digit;
            }

            numClone /= 10;
            index++;
        }

        index = 0;
        // Keep track of large index to swap. 
        largestDigitIndex = 0;
        largestDigit = 0;
        numClone = num;

        while (numClone > 0 && index < latestSmallerDigitIndex) {
            int digit = numClone % 10;

            if (digit > largestDigit) {
                largestDigit = digit;
                largestDigitIndex = index;
            }

            numClone /= 10;
            index++;
        }

        // cout << largestDigit << endl;

        // cout << latestSmallerDigitIndex << " " << largestDigitIndex << endl;
        
        // Now, need to swap indexes: latestSmallerDigitIndex and largestDigitIndex.
        num -= latestSmallerDigit * pow(10, latestSmallerDigitIndex);
        num += largestDigit * pow(10, latestSmallerDigitIndex);

        num -= largestDigit * pow(10, largestDigitIndex);
        num += latestSmallerDigit * pow(10, largestDigitIndex);

        return num;

    }
};