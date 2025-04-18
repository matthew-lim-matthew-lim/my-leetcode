// Last updated: 4/18/2025, 9:21:36 PM
class Solution {
public:
    int countLargestGroup(int n) {
        // n <= 10^4, so the max sum is 9*4 = 36, which is small. 
        // Therefore, we can keep track of the count of the number of numbers that sum to each sum.
        vector<int> numCount(37, 0);
        for (int i = 1; i <= n; i++) {
            int curr = i;
            int digitSum = 0;
            while (curr > 0) {
                digitSum += curr % 10;
                curr /= 10;
            }

            numCount[digitSum]++;
        }

        int largestDigitSum = *max_element(numCount.begin(), numCount.end());
        int elementCount = 0;
        for (int count : numCount) {
            elementCount += (count == largestDigitSum);
        }

        return elementCount;
    }
};