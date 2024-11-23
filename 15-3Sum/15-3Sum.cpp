class Solution {
public:
    // Custom hash function for std::vector<int>
    struct VectorHash {
        size_t operator()(const vector<int>& vec) const {
            size_t curr_hash = 0;
            for (int num : vec) {
                curr_hash ^= hash<int>()(num) + 0x9e3779b9 + (curr_hash << 6) + (curr_hash >> 2);
            }
            return curr_hash;
        }
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        // Solved in 42:30

        // Select a number, and then use 2 pointers.
        // By first selecting a number, we have converted the problem into a 2 sum problem. 

        // This is O(n^2) since we select 'n' first numbers, and perform a 2 pointer on each, which is 
        // 'n' time for each one.

        // Can deal with the duplicates in before insertion or when finished. 
        // Before: Sorting the numbers first and then using an unordered set?
        // After: Sorting the triplets after and then removing duplicates?
        // Before only works if you sort the array of 3 each time before you insert it into the set. 

        // Sort the array so that we can use 2 pointers on it
        sort(nums.begin(), nums.end());

        unordered_set<vector<int>, VectorHash> res_set;

        // Select one number to be the starting number. 
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // Perform 2 pointers to select the other 2 numbers.
            int l_ptr = i + 1;
            int r_ptr = nums.size() - 1;

            while (l_ptr < r_ptr) {
                if (i == l_ptr || i == r_ptr) {
                    if (i == l_ptr) {
                        l_ptr++;
                    } else {
                        r_ptr--;
                    }
                    continue;
                }
                if (l_ptr < r_ptr && nums[i] + nums[l_ptr] + nums[r_ptr] == 0) {
                    // Sort it, then put it in the solution set.
                    vector<int> curr_res = {nums[i], nums[l_ptr], nums[r_ptr]};

                    res_set.insert(curr_res);
                }
                if (nums[i] + nums[l_ptr] + nums[r_ptr] > 0) {
                    r_ptr--;
                } else {
                    l_ptr++;
                }
            } 
        } 

        return {res_set.begin(), res_set.end()};
    }
};