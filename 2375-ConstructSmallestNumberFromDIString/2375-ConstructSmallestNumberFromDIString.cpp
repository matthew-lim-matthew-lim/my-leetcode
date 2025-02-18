class Solution {
public:
    string smallestNumber(string pattern) {
        // Maybe put all the D values you come accross into a stack. When you reach the next I or the end of the string, fill that last spot
        // and then pop from the D stack and assign them values in ascending order.
        stack<int> stk;
        // The int is the index we assign.
        string res(pattern.size() + 1, '.');

        int currVal = 1;
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'I') {
                res[i] = currVal + '0';
                currVal++;
                while (!stk.empty()) {
                    int index = stk.top();
                    stk.pop();

                    res[index] = currVal + '0';
                    currVal++;
                }
            } else if (pattern[i] == 'D') {
                stk.push(i);
            }
        }
        stk.push(pattern.size());
        while (!stk.empty()) {
            int index = stk.top();
            stk.pop();

            res[index] = currVal + '0';
            currVal++;
        }

        return res;
    }
};