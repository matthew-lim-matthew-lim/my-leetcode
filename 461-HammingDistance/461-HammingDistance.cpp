// Last updated: 4/25/2025, 1:10:26 PM
class Solution {
public:
    int hammingDistance(int x, int y) {
        // Go through it bitwise.
        // Get the highest of x and y. 
        // Get the number of bits at this highest. 
        // Each time try and subtract the highest bit.
        // If a subtraction is possible, then there is a bit there.
        int larger = max(x, y);
        if (larger == 0) {
            return 0;
        }
        int bits = log(larger) / log(2);

        int res = 0;

        // Then, compare if there are bits for each x and y.
        for (int i = bits; i >= 0; i--) {
            bool xCurrBit = false;
            if (x - pow(2, i) >= 0) {
                x -= pow(2, i);
                xCurrBit = true;
            }
            bool yCurrBit = false;
            if (y - pow(2, i) >= 0) {
                y -= pow(2, i);
                yCurrBit = true;
            }
            if (xCurrBit != yCurrBit) {
                res++;
            }
        }

        return res;
    }
};