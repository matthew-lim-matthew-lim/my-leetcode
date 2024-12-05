class Solution {
public:
    bool canChange(string start, string target) {
        int L_count_S = 0;
        int R_count_S = 0;
        int L_count_T = 0;
        int R_count_T = 0; 
        string LR_order_S;
        string LR_order_T;

        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'R' || start[i] == 'L') {
                LR_order_S += start[i];
            }
            if (target[i] == 'R' || target[i] == 'L') {
                LR_order_T += target[i];
            }
            if (start[i] == 'R') {
                R_count_S++;
            } else if (start[i] == 'L') {
                L_count_S++;
            }
            if (target[i] == 'R') {
                R_count_T++;
            } else if (target[i] == 'L') {
                L_count_T++;
            }

            // If the target currently has less 'L' in this position.
            if (L_count_T < L_count_S) {
                cout << "1" << endl;
                return false;
            }
            // If the target currently has more 'R' in this position.
            if (R_count_S < R_count_T) {
                cout << "2" << endl;
                return false;
            }
        }

        if (LR_order_S != LR_order_T) {
            cout << "3" << endl;
            return false;
        }

        return true;
    }
};