class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Should be a even number of each element. 
        unordered_map<int, int> numCount;
        int numOdd = 0;
        for (int &val : nums) {
            numCount[val]++;
            if (numCount[val] % 2 == 1) {
                numOdd++;
            } else {
                numOdd--;
            }
        }
        return numOdd == 0;
    }
};