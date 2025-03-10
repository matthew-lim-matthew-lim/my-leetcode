class Solution {
public:
    bool valid(unordered_map<char, int> &vowelCount, int k) {
        if (k != 0) {
            return false;
        }
        if (vowelCount['a'] == 0 || 
            vowelCount['e'] == 0 || 
            vowelCount['i'] == 0 ||
            vowelCount['o'] == 0 ||
            vowelCount['u'] == 0
        ) {
            return false;
        }
        return true;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();

        long long res = 0;
        // Sliding Window.
        // If a window meets the requirements, count it, and move the left pointer until
        // it does not meet the requirmeents. 
        unordered_map<char, int> vowelCount = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};

        // Precompute so that we know at each index, how many vowels follow. 
        // Compute this back to front. 
        vector<int> vowelPostFix(n, 0);
        int currVowelCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            vowelPostFix[i] = currVowelCount;
            if (vowelCount.contains(word[i])) {
                currVowelCount++;
            } else {
                currVowelCount = 0;
            }
        }

        // for (int i : vowelPostFix) {
        //     cout << i << " ";
        // }
        // cout << endl;

        int l_ptr = 0;
        for (int r_ptr = 0; r_ptr < n; r_ptr++) {
            if (vowelCount.contains(word[r_ptr])) {
                vowelCount[word[r_ptr]]++;
            } else {
                k--;
            }

            while (valid(vowelCount, k) || k < 0) {
                if (valid(vowelCount, k)) {
                    // cout << l_ptr << " " << r_ptr << endl;
                    res++;
                    res += vowelPostFix[r_ptr];
                }

                if (vowelCount.contains(word[l_ptr])) {
                    vowelCount[word[l_ptr]]--;
                } else {
                    k++;
                }
                l_ptr++;
            }
        }

        return res;
    }
};