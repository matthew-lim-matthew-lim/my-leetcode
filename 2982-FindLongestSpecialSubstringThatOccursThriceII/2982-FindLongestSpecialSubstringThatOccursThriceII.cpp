class Solution {
public:
    bool checker(string& s, int test_len) {
        unordered_map<char, int> char_count;

        int curr_count = 1;
        for (int i = 1; i < s.size() + 1; i++) {
            if (i == s.size() || s[i] != s[i - 1]) {
                if ((curr_count + 1 - test_len) > 0) {
                    // `l + 1 - k`
                    char_count[s[i - 1]] += (curr_count + 1 - test_len);
                }
                curr_count = 1;
            } else {
                curr_count++;
            }
        }

        int max_val = 0;

        for (pair<char, int> entry : char_count) {
            max_val = max(max_val, entry.second);
        }

        cout << max_val << endl;

        return max_val >= 3;
    }

    int binarysearch(string& s) {
        int lo = 1;
        int hi = s.size();
        int bestSoFar = -1;
        // Range [lo, hi];
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (checker(s, mid)) {
                bestSoFar = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return bestSoFar;
    }

    int maximumLength(string s) {
        // Maybe binary search for the longest length.
        // For each length see if there exists 3 substrings with that length. 

        // The number of `k` length selections available for a length of `l` characters is `l + 1 - k`.
        // Therefore, can just keep track of the length of each special substring (we call length `k`),
        // and add `k-1` to a map of substring counts for each character.

        int res = binarysearch(s);

        return res;
    }
};