class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int currOdd = 0;
        int currEven = 0;
        long long res = 0;

        for (int num : arr) {
            if (num % 2 != 0) {
                int tmp = currOdd;
                currOdd = currEven + 1;
                currEven = tmp;
            } else {
                currEven++;
            }
            currOdd %= 1000000007;
            currEven %= 1000000007;
            res += currOdd % 1000000007;
        }

        return res % 1000000007;
    }
};