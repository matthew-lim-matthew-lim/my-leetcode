class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> count(A.size() + 1, 0);
        vector<int> res(A.size(), 0);
        int currRes = 0;
        for (int i = 0; i < A.size(); ++i) {
            count[A[i]]++;
            count[B[i]]++;
            if (A[i] != B[i]) {
                if (count[A[i]] == 2) {
                    currRes++;
                }
                if (count[B[i]] == 2) {
                    currRes++;
                }
            } else {
                if (count[A[i]] == 2) {
                    currRes++;
                }
            }
            res[i] = currRes;
        }

        return res;
    }
};