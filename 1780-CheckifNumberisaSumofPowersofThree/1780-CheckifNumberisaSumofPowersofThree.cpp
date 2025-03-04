class Solution {
public:
    bool checkPowersOfThree(int n) {
        // This is like binary but base 3. We can approach this question in a similiar manner.
        // log _{3}10^7 = 14.67... 
        int curr = 0;
        for (int i = 15; i >= 0; i--) {
            if (curr + pow(3, i) <= n) {
                curr += pow(3, i);
            }
        }

        return curr == n;
    }
};