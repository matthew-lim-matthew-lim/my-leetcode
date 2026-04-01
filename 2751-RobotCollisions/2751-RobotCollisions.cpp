// Last updated: 4/2/2026, 12:57:05 AM
1/* 
2First, sort by position. 
3Keep a stack of robots moving rightwards. 
4When we reach a leftward robot, we can deal with robots at the top of the stack. 
5
6 */
7struct Robot {
8    int position;
9    int ogPosition;
10    int health;
11    bool right;
12
13    bool operator<(const Robot& other) const {
14        return position < other.position;
15    }
16};
17
18class Solution {
19public:
20    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
21        int n = positions.size();
22
23        vector<Robot> robots(n);
24
25        for (int i = 0; i < n; i++) {
26            robots[i] = Robot{
27                positions[i],
28                i,
29                healths[i],
30                directions[i] == 'R'
31            };
32        }
33
34        sort(robots.begin(), robots.end());
35
36        deque<Robot> stk;
37        vector<Robot> res;
38
39        for (int i = 0; i < n; i++) {
40            Robot& robot = robots[i];
41            if (robot.right) {
42                stk.push_back(robot);
43            } else {
44                // Collision.
45                bool keep = true;
46                while (!stk.empty() && stk.back().health <= robot.health) {
47                    if (stk.back().health == robot.health) {
48                        keep = false;
49                        stk.pop_back();
50                        break;
51                    }
52                    robot.health--;
53                    stk.pop_back();
54                }
55                if (keep && !stk.empty() && stk.back().health > robot.health) {
56                    keep = false;
57                    // cout << i << " " << robot.right << endl;
58                    stk.back().health--;
59                }
60                if (keep && robot.health > 0) {
61                    res.push_back(robot);
62                }
63            }
64        }
65
66        while (!stk.empty()) {
67            res.push_back(stk.front());
68            stk.pop_front();
69        }
70
71        map<int, int> realRes;
72        for (int i = 0; i < res.size(); i++) {
73            realRes[res[i].ogPosition] = res[i].health;
74        }
75
76        vector<int> realRealRes;
77        for (auto p : realRes) {
78            realRealRes.push_back(p.second);
79        }
80
81        return realRealRes;
82    }
83};