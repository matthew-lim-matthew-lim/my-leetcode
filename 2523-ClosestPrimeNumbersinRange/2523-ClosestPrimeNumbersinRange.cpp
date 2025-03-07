class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // The simplest way to check if a number n is prime is to check any 
        // prime number up to sqrt(n) divides n. If not, n is prime.

        // However, since we're programmers, we can use Sieve of Eratosthenes.
        // Mark all multiples of 2 up to 'n'. Mark all multiples of 3 up to 'n', etc.
        vector<bool> prime(right + 1, true);
        for (int i = 2; i * i < right + 1; i++) {
            // We are sieving all multiples of this number.
            for (int j = i * i; j < right + 1; j += i) {
                prime[j] = false;
            }
        }
        // 1 is neither prime nor composite
        prime[1] = false;   

        // Find the smallest difference.
        vector<int> res = {left, right + 1};
        int prevIndex = -1;
        for (int i = left; i < right + 1; i++) {
            if (prime[i] == true) {
                if (prevIndex != -1 && (res[1] - res[0]) > (i - prevIndex)) {
                    res[0] = prevIndex;
                    res[1] = i;
                } 
                prevIndex = i;
            }
        }

        return (res[0] == left && res[1] == right + 1) ? vector<int>{ -1, -1 } : res;
    }
};