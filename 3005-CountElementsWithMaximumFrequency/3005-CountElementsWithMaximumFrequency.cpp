// Last updated: 9/23/2025, 12:14:05 AM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // O(n) with a hashmap
        unordered_map<int, int> numCount;
        for (int &num : nums) {
            numCount[num]++;
        }

        int highestCount = 0;
        int sum = 0;
        for (pair<const int, int>& p : numCount) {
            if (p.second == highestCount) {
                sum += p.second;
            }
            if (p.second > highestCount) {
                highestCount = p.second;
                sum = p.second;
            }
        }

        return sum;
    }
};