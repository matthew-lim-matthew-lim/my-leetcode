// Last updated: 4/13/2025, 8:18:58 PM
class Solution {
public:
    int MOD = 1000000007;
    long long fastPower(long long base, long long power) {
        long long result = 1;
        while(power > 0) {

            if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
                result = (result*base) % MOD;
            }
            base = (base * base) % MOD;
            power = power / 2; // Can also use power >>= 1; to make code even faster
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        int MOD = 1000000007;
        // Is this lowkey easy?
        // At even: 5 different options
        // At odd: 4 different options
        return (fastPower(5, (n / 2) + (n % 2)) * fastPower(4, (n / 2))) % MOD;
    }
};