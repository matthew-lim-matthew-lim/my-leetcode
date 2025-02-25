class Solution {
public:
    bool confusingNumber(int n) {
        // Kinda funny problem
        // Attempt rotation, if n contains any of 2, 3, 4, 5, 7, then abort. 
        int newN = 0;
        int oldN = n;
        int numLen = 0;
        while (n > 0) {
            numLen++;
            n /= 10;
        }

        unordered_set<int> invalid({2, 3, 4, 5, 7});

        for (int i = 0; i < numLen; i++) {
            int currN = (oldN / static_cast<int>(pow(10, i))) % 10;
            if (invalid.contains(currN)) return false;

            if (currN == 6) {
                currN = 9;
            } else if (currN == 9) currN = 6;

            newN += currN * pow(10, numLen - 1 - i);
        }

        return newN != oldN;
    }
};