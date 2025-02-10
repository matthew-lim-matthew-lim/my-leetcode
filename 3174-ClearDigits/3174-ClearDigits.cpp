class Solution {
public:
    string clearDigits(string s) {
        // Use a stack.
        stack<char> stk;
        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                stk.push(c);
            } else {
                stk.pop();
            }
        }

        string res(stk.size(), '.');
        for (int i = stk.size() - 1; i >= 0; i--) {
            char c = stk.top();
            stk.pop();

            res[i] = c;
        }

        return res;
    }
};