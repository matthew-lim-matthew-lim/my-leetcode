// Last updated: 5/12/2025, 9:10:01 PM
class Solution {
public:
/* 
Any integer that ends in an even number is even. 
3 elements only. 

Backtracking
 */
    struct Entry {
        int num1;
        int num2;
        int num3;

        bool operator==(const Entry &other) const {
            return num1 == other.num1 && num2 == other.num2 && num3 == other.num3;
        }
    };

    struct EntryHash {
        size_t operator()(const Entry &entry) const {
            return hash<int>()(entry.num1) + (hash<int>()(entry.num2) << 1) + (hash<int>()(entry.num3) << 2);
        }
    };

    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<Entry, EntryHash> set;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 == 1) continue;

                    set.insert(Entry(digits[i], digits[j], digits[k]));
                }
            }
        }

        vector<int> res;

        for (const Entry &entry : set) {
            res.emplace_back(100 * entry.num1 + 10 * entry.num2 + entry.num3);
        }

        sort(res.begin(), res.end());

        return res;
    }
};