// Last updated: 4/22/2025, 5:07:30 PM
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<vector<int>> divs;
    vector<long long> fact, invFact;

    int n, maxValue;

    int power(long long x, int y) {
        long long res = 1;
        while (y > 0) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    int nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int idealArrays(int _n, int _maxValue) {
        n = _n;
        maxValue = _maxValue;

        // Precompute factorials
        // At most 14 prime factors
        int maxF = n + 14;  
        fact.resize(maxF + 1, 1);
        invFact.resize(maxF + 1, 1);
        for (int i = 1; i <= maxF; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[maxF] = power(fact[maxF], MOD - 2);
        for (int i = maxF - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        // Precompute divisors
        divs.assign(maxValue + 1, {});
        for (int i = 1; i <= maxValue; ++i)
            for (int j = i * 2; j <= maxValue; j += i)
                divs[i].push_back(j);

        // DP: dp[x] = number of ways to build chains of different lengths ending in x
        vector<vector<int>> count(maxValue + 1, vector<int>(15));
        for (int i = 1; i <= maxValue; ++i) count[i][1] = 1;

        for (int l = 2; l <= 14; ++l) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j : divs[i]) {
                    count[j][l] = (count[j][l] + count[i][l - 1]) % MOD;
                }
            }
        }

        // Combine all sequences of length k with binomial(n - 1, k - 1)
        int res = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int k = 1; k <= 14; ++k) {
                int ways = count[i][k];
                res = (res + (long long)ways * nCr(n - 1, k - 1) % MOD) % MOD;
            }
        }

        return res;
    }
};
