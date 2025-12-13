// Last updated: 12/13/2025, 11:57:48 PM
1class Solution {
2public:
3    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
4        // Process them and put all the valid ones into a vector of pairs, sort that, and then return result.
5        int n = code.size();
6
7        vector<string> res;
8
9        vector<pair<string, string>> pairs;
10
11        regex r("^[a-zA-Z0-9_]*$");
12        
13        for (int i = 0; i < n; i++) {
14            if (!isActive[i] || !regex_match(code[i], r) || code[i].size() == 0) {
15                continue;
16            }
17
18            if (!(businessLine[i] == "electronics" || 
19                 businessLine[i] == "grocery" ||
20                 businessLine[i] == "pharmacy" ||
21                 businessLine[i] == "restaurant"
22            )) {
23                continue;
24            } 
25
26            pairs.push_back({ businessLine[i], code[i] });
27        }
28
29        sort(pairs.begin(), pairs.end());
30
31        for (pair<string, string> &pair : pairs) {
32            res.push_back(pair.second);
33        }
34
35        return res;
36    }
37};