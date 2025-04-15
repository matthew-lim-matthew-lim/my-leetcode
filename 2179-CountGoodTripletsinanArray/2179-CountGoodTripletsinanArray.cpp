// Last updated: 4/15/2025, 1:36:12 PM
class Solution {
public:
// Is this the number of common subsets of length 3??? That would be crazy. 
// I think it is lol

// Maybe count the number of common subsets of length 2. Then, do another pass to find the number of common subsets of 
// length 3. 
// DP

    class FenwickTree {
    private:
        vector<int> tree;

    public:
        FenwickTree(int size) : tree(size + 1, 0) {}

        void update(int index, int delta) {
            index++;
            while (index < tree.size()) {
                tree[index] += delta;
                index += index & -index;
            }
        }

        int query(int index) {
            index++;
            int res = 0;
            while (index > 0) {
                res += tree[index];
                index -= index & -index;
            }
            return res;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // For nums2, keep a map with key [number] and value, a set of all the numbers that preceded it. 
        // For nums1, iterate through with a set of all the numbers that precede it and numbers after it. 
        // Check if each number before it is in the num2 set, and number after is NOT in the num2 set. 

        // Build nums2 indexMap
        // vector<int> nums2Index(n);
        // for (int i = 0; i < n; i++) {
        //     nums2Index[nums2[i]] = i;
        // }

        // For each element in nums1, check if the elements up to it are matching.
        long long res = 0;

        // My original solution was O(n^2) (TLE). If we use a Fenwick tree we can replace the inner loop with a 
        // O(log n) query, which makes the TC O(n log n).

        vector<int> pos2(n), reversedIndexMapping(n);
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reversedIndexMapping[pos2[nums1[i]]] = i;
        }

        FenwickTree tree(n);

        // Iterate through nums1
        // currSet now contains all the elements
        unordered_set<int> nums1Set;
        for (int i = 0; i < n; i++) {
            // If nums2 contains a number in nums1Set
            // int currMatchesLeft = 0;
            // int currMatchesRight = (n - 1 - i);

            int pos = reversedIndexMapping[i];
            int currMatchesLeft = tree.query(pos);
            tree.update(pos, 1);
            int currMatchesRight = (n - 1 - pos) - (i - currMatchesLeft);
            // res += (long long)currMatchesLeft * currMatchesRight;

            // cout << currMatchesLeft << " " << currMatchesRight << endl;
            res += (long long)currMatchesLeft * currMatchesRight;

            nums1Set.insert(nums1[i]);
        }

        return res;
    }
};