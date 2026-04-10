// Last updated: 4/10/2026, 10:44:17 PM
1class Solution {
2public:
3    string addStrings(string num1, string num2) {
4        int n1 = num1.size();
5        int n2 = num2.size();
6
7        string res;
8        int index = 0;
9        bool carry = false;
10        for (; index < max(n1, n2); index++) {
11            int nextInt = 0; 
12            if (index < n1) {
13                nextInt += (num1[n1 - 1 - index] - '0');
14            }
15            if (index < n2) {
16                nextInt += (num2[n2 - 1 - index] - '0');
17            }
18
19            if (carry) {
20                nextInt++;
21                carry = false;
22            }
23
24            if (nextInt >= 10) {
25                carry = true;
26            }
27
28            res += to_string(nextInt % 10);
29        }
30        if (carry) {
31            res += '1';
32        }
33
34        reverse(res.begin(), res.end());
35
36        return res;
37    }
38};