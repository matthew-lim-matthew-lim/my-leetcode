// Last updated: 4/18/2025, 12:42:51 PM
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string temp = "1";

        for (int i = 2; i <= n; i++) {
            string curr = "";
            int count = 1;

            for (int j = 1; j <= temp.size(); j++) {
                if (j < temp.size() && temp[j] == temp[j - 1]) {
                    count++;
                } else {
                    curr += to_string(count);
                    curr += temp[j - 1];
                    count = 1;
                }
            }

            temp = curr;
        }

        return temp;
    }
};
