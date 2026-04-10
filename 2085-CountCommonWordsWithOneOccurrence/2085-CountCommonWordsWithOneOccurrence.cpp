// Last updated: 4/10/2026, 10:50:49 PM
1class Solution {
2public:
3    int countWords(vector<string>& words1, vector<string>& words2) {
4        unordered_map<string, int> words1Map;
5        for (string& word : words1) {
6            words1Map[word]++;
7        }
8
9        unordered_map<string, int> words2Map;
10        for (string& word : words2) {
11            words2Map[word]++;
12        }
13
14        int res = 0;
15        for (pair<const string, int>& entry : words1Map) {
16            if (entry.second == 1 &&
17                words2Map[entry.first] == 1
18            ) {
19                res++;
20            }
21        }
22
23        return res;
24    }
25};