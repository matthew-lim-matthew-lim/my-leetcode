class Solution {
public:
    long long factorial(int x) {
        long long result = 1;
        for (int i = 1; i <= x; ++i) {
            result *= i;
        }
        return result;
    }

    long long combination(int n, int r) {
        if (r > n) return 0;
        return factorial(n) / (factorial(r) * factorial(n - r));
    }

    int tupleSameProduct(vector<int>& nums) {
        
        // Each combination unique [a, b, c, d] where (a, b) and (c, d) are in any position, has 8 arrangements. 
        // Consider each combination of 4 numbers that produces that result we need. 
        // Sort the combination so that we can check in a 4d matrix to see if that combination has been used.
        int n = nums.size();

        // We should be able to do this in O(n^2)
        unordered_map<int, int> values;

        int res = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                values[nums[a] * nums[b]]++;
            }
        }

        for (auto p : values) {
            res += 8 * combination(p.second, 2);
        }

        return res;
    }
};