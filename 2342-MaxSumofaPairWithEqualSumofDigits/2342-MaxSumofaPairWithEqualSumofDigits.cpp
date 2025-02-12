class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // Map the sum of the digits to an ordered set of the number. 
        // When adding a number, update the max value of `nums[i] + nums[j]` using the map.
        // This is an O(n log n) solution.
        unordered_map<int, priority_queue<int>> numsMap;
        int currMax = -1;
        for (int num : nums) {
            int curr = num;
            int digitSum = 0;
            while (curr > 0) {
                digitSum += curr % 10;
                curr /= 10;
            }
            if (!numsMap[digitSum].empty()) {
                currMax = max(currMax, numsMap[digitSum].top() + num);
            }
            numsMap[digitSum].push(num);
        }
        return currMax;
    }
};