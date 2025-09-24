// Last updated: 9/24/2025, 10:28:22 PM
#include <string>
#include <vector>
#include <algorithm> // For std::min

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i][j] will store the minimum edit distance between
        // word1's first 'i' characters and word2's first 'j' characters.
        // We use (n+1) x (m+1) dimensions to handle empty string prefixes.
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

        // Base cases:
        // If word1 is empty (i=0), we need 'j' insertions to form word2's first 'j' chars.
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
        }
        // If word2 is empty (j=0), we need 'i' deletions to transform word1's first 'i' chars
        // into an empty string.
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }

        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // If the current characters match, no operation is needed for them.
                // The distance is simply the distance of the previous prefixes.
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // If characters do not match, we consider three operations:
                    // 1. Replace: Replace word1[i-1] with word2[j-1]. Cost: dp[i-1][j-1] + 1
                    // 2. Delete: Delete word1[i-1]. Cost: dp[i-1][j] + 1
                    // 3. Insert: Insert word2[j-1] into word1. Cost: dp[i][j-1] + 1
                    // We choose the minimum cost among these options.
                    dp[i][j] = std::min({
                        dp[i - 1][j - 1] + 1, // Replace
                        dp[i - 1][j] + 1,     // Delete
                        dp[i][j - 1] + 1      // Insert
                    });
                }
            }
        }

        // The result is the edit distance between the full word1 and full word2.
        return dp[n][m];
    }
};