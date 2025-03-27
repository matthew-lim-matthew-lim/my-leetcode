// Last updated: 3/27/2025, 7:07:01 PM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // Precompute + iterate.
        // Use a map. 
        // { count, unordered set of { number } }
        map<int, unordered_set<int>> countToNumLeft;
        unordered_map<int, int> numToCountLeft;

        map<int, unordered_set<int>> countToNumRight;
        unordered_map<int, int> numToCountRight;
        
        for (int &num : nums) {
            if (!numToCountRight.contains(num)) {
                countToNumRight[1].insert(num);
                numToCountRight[num] = 1;
            } else {
                countToNumRight[numToCountRight[num]].erase(num);
                if (countToNumRight[numToCountRight[num]].empty()) {
                    countToNumRight.erase(numToCountRight[num]);
                }
                numToCountRight[num]++;
                countToNumRight[numToCountRight[num]].insert(num);
            }
        }

        // for (auto p : countToNumRight) {
        //     cout << p.first << ": " << endl;
        //     for (int num : p.second) {
        //         cout << num << endl;
        //     }
        // }

        // Now, iterate through nums.
        // Ignore cutting at the edges where either could be empty. 

        for (int i = 0; i < nums.size() - 1; i++) {
            // cout << "GOING THROUGH " << i << endl;
            int num = nums[i];
            countToNumRight[numToCountRight[num]].erase(num);

            if (countToNumRight[numToCountRight[num]].empty()) {
                countToNumRight.erase(numToCountRight[num]);
            }
            numToCountRight[num]--;
            if (numToCountRight[num] == 0) {
                numToCountRight.erase(num);
            } else {
                countToNumRight[numToCountRight[num]].insert(num);
            }

            if (numToCountLeft[num] == 0) {
                countToNumLeft[1].insert(num);
                numToCountLeft[num] = 1;
            } else {
                countToNumLeft[numToCountLeft[num]].erase(num);
                if (countToNumLeft[numToCountLeft[num]].empty()) {
                    countToNumLeft.erase(numToCountLeft[num]);
                }
                numToCountLeft[num]++;
                countToNumLeft[numToCountLeft[num]].insert(num);
            }

            // for (auto p : countToNumLeft) {
            //     cout << p.first << ": " << endl;
            //     for (int val : p.second) {
            //         cout << val << endl;
            //     }
            // }
            // for (auto p : countToNumRight) {
            //     cout << p.first << ": " << endl;
            //     for (int val : p.second) {
            //         cout << val << endl;
            //     }
            // }

            // Check if any result.
            if (countToNumRight.rbegin() != countToNumRight.rend() &&
                countToNumLeft.rbegin() != countToNumLeft.rend() &&
                countToNumRight.rbegin()->second.size() == 1 && 
                countToNumLeft.rbegin()->second.size() == 1 && 
                *countToNumLeft.rbegin()->second.begin() == *countToNumRight.rbegin()->second.begin() &&
                countToNumLeft.rbegin()->first > ((i + 1) / 2.0) &&
                countToNumRight.rbegin()->first > ((nums.size() - (i + 1)) / 2.0)
            ) {
                return i;
            }
        }

        return -1;
    }
};