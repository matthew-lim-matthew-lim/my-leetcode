class Solution {
public:
    int binToInt(string s) {
        int currSum = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                currSum += pow(2, (s.size() - 1 - i));
            }
        }
        return currSum;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        // Is this backtracking?
        // We could just convert the binary string into number, and just get the first number that was not input.
        // This is really fast as nums.size() <= 16;
        unordered_set<int> usedNums;
        for (string binNum : nums) {
            usedNums.insert(binToInt(binNum));
        }
        usedNums.insert(-1);

        int intRes = -1;
        while (usedNums.contains(intRes)) {
            intRes++;
        }

        // Convert from int to binary
        string res;
        int length = nums[0].size();
        for (int i = length - 1; i >= 0; i--) {
            if (intRes - pow(2, i) >= 0) {
                res += "1";
                intRes -= pow(2, i);
            } else {
                res += "0";
            }
        }

        return res;
    }
};