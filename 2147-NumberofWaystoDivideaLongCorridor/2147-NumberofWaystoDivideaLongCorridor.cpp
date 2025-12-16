// Last updated: 12/16/2025, 9:26:09 PM
1/* 
2You only every move the dividers around the plants, never the seats.
3You need to place the dividers greedily:
4- Place the divider start as early as you can.
5- Place the divider end as late as you can (past the plants). 
6- The number of plants in between gives you a number of possible plant positions. 
7 */
8class Solution {
9public:
10    int numberOfWays(string corridor) {
11        struct Chair {
12            int start;
13            int end;
14        };
15
16        int chairCount = 0;
17        vector<Chair> currChairs;
18        int n = corridor.size();
19        currChairs.push_back(Chair{ 0, 0 });
20        for (int i = 0; i < n; i++) {
21            if (corridor[i] == 'S') {
22                chairCount++;
23            } 
24            if (chairCount == 0) {
25                currChairs.back().start = i;
26            }
27            if (chairCount == 2) {
28                currChairs.back().end = i;
29                currChairs.push_back(Chair{ i, i });
30                chairCount = 0;
31            }
32        }
33        if (currChairs.size() > 0 && currChairs.back().start >= currChairs.back().end) {
34            currChairs.pop_back();
35        }
36
37        // for (int i = 0; i < currChairs.size(); i++) {
38        //     cout << currChairs[i].start << " " << currChairs[i].end << endl;
39        // }
40
41        if (currChairs.empty() || (chairCount % 2 == 1)) {
42            return 0;
43        }
44
45        long long res = 1;
46        for (int i = 1; i < currChairs.size(); i++) {
47            int distance = currChairs[i].start - currChairs[i-1].end + 1;
48            res *= distance;
49            res %= 1'000'000'007;
50        }
51
52        return res;
53    }
54};