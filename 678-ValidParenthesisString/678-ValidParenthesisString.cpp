// Last updated: 7/16/2025, 12:55:23 AM
/* 
STACK!
 */

class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int, char>> stk;
        stack<int> stkA;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                stk.push({ i, '(' });
            } else if (c == ')') {
                bool used = false;
                if (!stk.empty() && stk.top().second == '(') {
                    used = true;
                    stk.pop();
                } else if (!stkA.empty()) {
                    stkA.pop();
                    used = true;
                }
                if (!used) {
                    stk.push({ i, ')' });
                }
            } else {
                stkA.push(i);
            }
        }

        while (!stk.empty() && !stkA.empty()) {
            while (!stkA.empty()) {
                int aTop = stkA.top();
                stkA.pop();

                if (stk.top().first < aTop && stk.top().second == '(') {
                    stk.pop();
                    break;
                }
            }
        }

        return stk.empty();
    }
};