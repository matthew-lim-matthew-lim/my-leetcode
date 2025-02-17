#include <ranges>

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int ans = 0;
        
        array<int, 26> freq = {};
        for (char c : tiles)
            freq[c - 'A']++;

        array<int, 8> fac = {1};
        for (int n = 1; n < fac.size(); n++)
            fac[n] = n * fac[n-1];

        auto C = [&](int n, int k) -> int {
            assert(k <= n);
            return fac[n] / (fac[k] * fac[n - k]);
        };

        vector<array<int, 26>> dp(tiles.size() + 1);
        ranges::fill(ranges::join_view(dp), -1);

        auto dfs = [&](this const auto &self, int pos, int spaces) -> int {
            if (pos >= freq.size())
                return spaces == 0;

            if (dp[spaces][pos] != -1)
                return dp[spaces][pos];

            int res = 0;

            for (int use = 0; use <= min(spaces, freq[pos]); use++)
                res += C(spaces, use) * self(pos + 1, spaces - use);

            return dp[spaces][pos] = res;
        };

        for (int spaces = 1; spaces <= tiles.size(); spaces++)
            ans += dfs(0, spaces);

        return ans;
    }
}