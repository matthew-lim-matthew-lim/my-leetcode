class Solution {
public:
    int maxScore(string s) {
        // Prefix sum I think.
        vector<int> left_zeros(s.size(), 0);
        vector<int> right_ones(s.size(), 0);

        int zero_count = 0;
        int one_count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') zero_count++;
            left_zeros[i] = zero_count;
            if (s[(s.size() - 1) - i] == '1') one_count++;
            right_ones[(s.size() - 1) - i] = one_count;
        }

        // Find the best score.
        int best_score = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            best_score = max(best_score, left_zeros[i] + right_ones[i + 1]);
        }

        return best_score;
    }
};