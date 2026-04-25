// Last updated: 4/25/2026, 6:08:17 PM
1class Solution {
2public:
3    int maxDistToClosest(vector<int>& seats) {
4        int res = 0;
5        int lastPerson = 0;
6        int n = seats.size();
7        bool firstPerson = true;
8        for (int i = 0; i < n; i++) {
9            lastPerson++;
10            if (seats[i]) {
11                res = max(res, lastPerson/2);
12                if (firstPerson) {
13                    res = lastPerson - 1;
14                    firstPerson = false;
15                }
16                lastPerson = 0;
17            }
18        }
19
20        res = max(res, lastPerson);
21
22        return res;
23    }
24};