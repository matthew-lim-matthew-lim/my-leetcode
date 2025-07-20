// Last updated: 7/21/2025, 12:11:34 AM
/* 
We can binary search this?
Basically, find the smallest nParts that will work. 

It succeeds if the number of parts we made (length of res array) is less than nParts.

Therefore, it is monotonic.
All the ones beyond the critical number will succeed (more than nParts).
All the one before the critical number will fail (less than nParts).
*/
class Solution {

struct AttemptObject {
    bool success;
    vector<string> result;
};
int limit_;

public:
    AttemptObject attempt(string &message, int nParts) {
        vector<string> res;

        int currPart = 1;

        int currIndex = 0;
        
        int n = message.size();
        int i = 0;
        for (; i < nParts && currIndex < n; i++) {
            int suffixSize = 3 + to_string(i + 1).size() + to_string(nParts).size();
            string currString = "";

            for (int j = 0; j < limit_ - suffixSize && currIndex < n; j++) {
                currString += message[currIndex];
                currIndex++;
            }
            currString += "<" + to_string(i + 1) + "/" + to_string(nParts) + ">";
            res.push_back(currString);
        }

        if (currIndex != n) {
            return AttemptObject(false, {});
        }

        return AttemptObject(true, res);
    }

    vector<string> splitMessage(string message, int limit) {
        limit_ = limit;
        int n = message.size();



        AttemptObject res;

        for (int i = 4; i >= 1; i--) {
            int lo = pow(10, i - 1);
            int hi = pow(10, i);
            // cout << lo << ' ' << hi << endl;
            int bestSoFar = n;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                // cout << mid << endl;

                AttemptObject attemptObj = attempt(message, mid);
                if (attemptObj.success) {
                    hi = mid - 1;
                    bestSoFar = mid;
                    res = attemptObj;
                    // cout << "hello" << endl;
                } else {
                    lo = mid + 1;
                }
            }
        }

        return res.result;
    }
};