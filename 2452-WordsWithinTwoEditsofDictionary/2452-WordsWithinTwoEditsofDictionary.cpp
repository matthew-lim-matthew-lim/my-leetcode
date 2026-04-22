// Last updated: 4/22/2026, 9:56:41 PM
1/* 
2For each word in `queries`, test each word in `dictionary`. 
3 */
4class Solution {
5public:
6    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
7        vector<string> res;
8
9        for (const string &query : queries) {
10            for (const string &entry : dictionary) {
11                int differences = 0;
12
13                for (int i = 0; i < entry.size(); i++) {
14                    if (query[i] != entry[i]) {
15                        differences++;
16                    }
17                }
18
19                if (differences <= 2) {
20                    res.push_back(query);
21                    break;
22                }
23            }
24        }
25
26        return res;
27    }
28};