// Last updated: 9/15/2025, 10:25:14 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int currInt = 1;
        int currArrIndex = 0;
        while (k > 0 && currArrIndex < arr.size()) {
            if (currInt == arr[currArrIndex]) {
                currArrIndex++;
                currInt++;
            } else {
                k--;
                if (k == 0) {
                    break;
                }
                currInt++;
            }
        }

        while (k > 0) {
            k--;
            if (k == 0) {
                break;
            }
            currInt++;
        }

        return currInt;
    }
};