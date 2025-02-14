class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Calculations involving undefined numbers are always -1. 
        // Number divided by itself is 1.

        unordered_map<string, unordered_map<string, double>> equVals;
        for (int i = 0; i < equations.size(); i++) {
            string q1 = equations[i][0];
            string q2 = equations[i][1];
            equVals[q1][q2] = values[i];
            equVals[q2][q1] = 1 / values[i];
            for (auto& entry : equVals[q1]) {
                string x = entry.first;
                for (auto& entry2 : equVals[x]) {
                    string y = entry2.first;

                    double a = equVals[q1][x];
                    double b = equVals[x][y];
                    equVals[q1][y] = a * b;
                    equVals[y][q1] = 1 / (a * b);
                }
            }
            for (auto& entry : equVals[q2]) {
                string x = entry.first;
                for (auto& entry2 : equVals[x]) {
                    string y = entry2.first;

                    double a = equVals[q2][x];
                    double b = equVals[x][y];
                    equVals[q2][y] = a * b;
                    equVals[y][q2] = 1 / (a * b);
                }
            }
        }

        vector<double> res;
        for (vector<string>& q : queries) {
            string q1 = q[0];
            string q2 = q[1];

            // Check if either q1 or q2 is undefined. 
            if (!equVals.contains(q1) || !equVals.contains(q2)) {
                res.push_back(-1);
                continue;
            }

            // Check if q1 == q2
            if (q1 == q2) {
                res.push_back(1);
                continue;
            }

            char found = false;
            // Is this simply [q2, q1] = 1 / [q1, q2]
            if (equVals[q2].contains(q1)) {
                res.push_back(1 / equVals[q2][q1]);
                continue;
            }

            // Is this simply [q1, q2]
            if (equVals[q1].contains(q2)) {
                res.push_back(equVals[q1][q2]);
                continue;
            }

            // For some random [q1, x]. Does there exist a [x, q2], where x is the same.
            for (auto& entry : equVals[q1]) {
                string x = entry.first;
                if (equVals[q2].contains(x)) {
                    double a = equVals[q1][x];
                    double b = equVals[q2][x];
                    res.push_back(a / b);
                    found = true;
                    break;
                }
            }
            if (found) {
                continue;
            }
            res.push_back(-1);
        }

        return res;
    }
};