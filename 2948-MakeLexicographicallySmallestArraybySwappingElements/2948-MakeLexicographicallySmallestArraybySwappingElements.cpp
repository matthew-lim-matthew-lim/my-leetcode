class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Need to keep track of the numbers satisfying |nums[i] - nums[j]| <= 2.
        // We can do this by sorting the list, and using a sliding window. For each entry in the 
        // list track { value, index }. For each entry in the sliding window, if the index is out 
        // of order, swap it. 
        vector<pair<int, int>> nums_pair(nums.size(), {0, 0});
        for (int i = 0; i < nums.size(); i++) {
            nums_pair[i] = { nums[i], i };
        }

        sort(nums_pair.begin(), nums_pair.end());

        // Carry out sliding window. 
        // Group it by transitive chain. If we can swap the last element with the second last element, 
        // and we can keep adding elements, we can sort elements outside of the range of `limit`. 
        int l_ptr = 0;
        for (int r_ptr = 0; r_ptr <= nums_pair.size(); r_ptr++) {
            if ((r_ptr == nums_pair.size()) || 
                (l_ptr < r_ptr && abs(nums_pair[r_ptr].first - nums_pair[r_ptr - 1].first) > limit)) {
                r_ptr--;

                // Collect the indexes in this window, sort them, and re-assign them sorted.
                vector<int> indexes(r_ptr - l_ptr + 1, 0);
                for (int i = 0; i < indexes.size(); i++) {
                    indexes[i] = nums_pair[i + l_ptr].second;
                }
                sort(indexes.begin(), indexes.end());
                for (int i = 0; i < indexes.size(); i++) {
                    nums_pair[i + l_ptr].second = indexes[i];
                }

                r_ptr++;
                l_ptr = r_ptr;
            }


        }

        // Reconstruct the final array.
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums_pair.size(); i++) {
            res[nums_pair[i].second] = nums_pair[i].first;
        }

        return res;
    }
};