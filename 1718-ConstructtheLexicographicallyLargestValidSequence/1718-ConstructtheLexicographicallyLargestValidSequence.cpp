class Solution {
public:
    void backtrack(vector<int> res, set<int, greater<>> currNums, vector<int>& finalRes) {
        for (int e : res) {
            cout << e << " ";
        }
        cout << endl;
        if (!finalRes.empty()) {
            return;
        }
        if (currNums.empty()) {
            finalRes = res;
            return;
        }
        int nextIndex = 0;
        while (res[nextIndex] != -1) {
            nextIndex++;
        }
        vector<int> nextNums = {currNums.begin(), currNums.end()};
        for (int i = 0; i < nextNums.size(); i++) {
            int num = nextNums[i];
            int lastIndex = nextIndex + num;
            if (num == 1) {
                lastIndex = nextIndex;
            }
            if (lastIndex < res.size() && res[lastIndex] == -1) {
                res[nextIndex] = num;
                res[lastIndex] = num;
                currNums.erase(num);
                backtrack(res, currNums, finalRes);
                if (!finalRes.empty()) {
                    return;
                }
                res[nextIndex] = -1;
                res[lastIndex] = -1;
                currNums.insert(num);
            } 
        }
    }

    vector<int> constructDistancedSequence(int n) {
        // Basically, for any i, it is positioned abs(j - i) away, meaning that there is `i - 1` distance between them.
        // Do it greedily in descending order? 
        // Greedy backtracking in descending order. 
        // This is because in descending order, the first valid solution would be the best one.
        vector<int> res(2 * n - 1, -1);
        set<int, greater<>> currNums = {1};
        for (int i = 2; i <= n; i++) {
            currNums.insert(i);
        }

        vector<int> finalRes;

        backtrack(res, currNums, finalRes);

        return finalRes;
    }
};