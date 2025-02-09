class Solution {
public:
    // Optimized function to calculate combinations C(n, k)
    unsigned long long combination(int n, int k) {
        if (k < 0 || n < 0) {
            throw std::invalid_argument("n and k must be non-negative.");
        }
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;

        // Use symmetry property to reduce calculations
        if (k > n - k) k = n - k;

        unsigned long long result = 1;
        for (int i = 1; i <= k; ++i) {
            result *= (n - i + 1);
            result /= i;
        }
        return result;
    }

    long long countBadPairs(vector<int>& nums) {
        // This problem looks so O(n).
        long long res = 0;
        int n = nums.size();
        unordered_map<int, int> numMap;

        for (int i = 0; i < n; i++) {
            numMap[nums[i] + (n - i)]++;
        }

        for (pair<int, int> p : numMap) {
            res += combination(p.second, 2);
        }

        return combination(n, 2) - res;
    }
};