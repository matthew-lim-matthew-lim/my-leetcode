// Last updated: 3/29/2025, 4:43:57 PM
class Solution {
public:
    // Fast exponentiation: computes base^exp % mod
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    vector<int> sieveOfEratosthenes(int n) {
        vector<int> primeScores(n + 1, 0);
        for (int p = 2; p <= n; ++p) {
            if (primeScores[p] == 0) {
                for (int i = p; i <= n; i += p) {
                    primeScores[i]++;
                }
            }
        }
        return primeScores;
    }

    int maximumScore(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> primeScores = sieveOfEratosthenes(maxVal);

        vector<int> left(n), right(n);
        stack<int> st;

        // Left span
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && primeScores[nums[st.top()]] < primeScores[nums[i]]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Right span
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && primeScores[nums[st.top()]] <= primeScores[nums[i]]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Sort values descending
        vector<pair<int, int>> valWithIdx;
        for (int i = 0; i < n; ++i) {
            valWithIdx.emplace_back(nums[i], i);
        }
        sort(valWithIdx.rbegin(), valWithIdx.rend());

        long long res = 1;

        for (auto& [val, idx] : valWithIdx) {
            long long count = 1LL * left[idx] * right[idx];
            long long use = min((long long)k, count);
            res = res * modPow(val, use, MOD) % MOD;
            k -= use;
            if (k == 0) break;
        }

        return res;
    }
};
