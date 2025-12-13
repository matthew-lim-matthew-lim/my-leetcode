// Last updated: 12/14/2025, 12:44:18 AM
1/* 
2Put all the valid codes of each category in a vector for each. 
3Then sort the codes.
4Then concatenate the vectors.
5 */
6class Solution {
7public:
8    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
9        vector<string> elecCodes;
10        vector<string> grocCodes;
11        vector<string> pharCodes;
12        vector<string> restCodes;
13
14        int n = code.size();
15
16        for (int i = 0; i < n; i++) {
17            bool valid = true;
18            if (code[i].empty()) {
19                valid = false;
20            }
21            for (char c : code[i]) {
22                if ((c <= 'z' && c >= 'a') ||
23                    (c <= 'Z' && c >= 'A') ||
24                    (c <= '9' && c >= '0') ||
25                    (c == '_')
26                ) {
27                    continue;
28                }
29                valid = false;
30                break;
31            }
32
33            if (!isActive[i]) {
34                valid = false;
35            }
36
37            if (!valid) {
38                continue;
39            }
40
41            if (businessLine[i] == "electronics") {
42                elecCodes.push_back(code[i]);
43            }
44            if (businessLine[i] == "grocery") {
45                grocCodes.push_back(code[i]);
46            }
47            if (businessLine[i] == "pharmacy") {
48                pharCodes.push_back(code[i]);
49            }
50            if (businessLine[i] == "restaurant") {
51                restCodes.push_back(code[i]);
52            }
53        }
54
55        sort(elecCodes.begin(), elecCodes.end());
56        sort(grocCodes.begin(), grocCodes.end());
57        sort(pharCodes.begin(), pharCodes.end());
58        sort(restCodes.begin(), restCodes.end());
59
60        elecCodes.insert(elecCodes.end(), grocCodes.begin(), grocCodes.end());
61        elecCodes.insert(elecCodes.end(), pharCodes.begin(), pharCodes.end());
62        elecCodes.insert(elecCodes.end(), restCodes.begin(), restCodes.end());
63
64        return elecCodes;
65    }
66};