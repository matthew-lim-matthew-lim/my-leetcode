// Last updated: 3/29/2026, 4:19:35 PM
1/* 
2Keep an unordered_map with `t` and update the counts.
3Check each step that the count of each character of the unordered_map is beyond `t`. 
4*/
5class Solution {
6private:
7    unordered_map<char, int> cMap;
8    unordered_map<char, int> target;
9public:
10    bool checkCounts() {
11        for (const pair<char, int> &p : target) {
12            if (!cMap.contains(p.first) || cMap[p.first] < p.second) {
13                return false;
14            }
15        } 
16
17        return true;
18    }
19
20    string minWindow(string s, string t) {
21        for (char c : t) {
22            target[c]++;
23        }
24
25        int n = s.size();
26
27        pair<int, int> best = {0, INT_MAX};
28        
29        int l_ptr = 0;
30        for (int r_ptr = 0; r_ptr < n; r_ptr++) {
31            cMap[s[r_ptr]]++;
32            while (checkCounts()) {
33                if (r_ptr - l_ptr < best.second - best.first) {
34                    best = { l_ptr, r_ptr };
35                }
36                cMap[s[l_ptr]]--;
37                l_ptr++;
38            }
39        }
40
41        return best.second == INT_MAX ? "" : s.substr(best.first, best.second - best.first + 1);
42    }
43};