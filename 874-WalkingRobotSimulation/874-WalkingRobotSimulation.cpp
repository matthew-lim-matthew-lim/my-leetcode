// Last updated: 4/7/2026, 12:25:47 AM
1class Direction;
2
3class Coord {
4public:
5    Coord() : y(0), x(0) {}
6
7    Coord(int yNew, int xNew) : y(yNew), x(xNew) {}
8
9    Coord& operator+=(const Coord &other) {
10        y += other.y;
11        x += other.x;
12        return *this;
13    }
14
15    Coord operator+(const Coord &other) {
16        return Coord(y + other.y, x + other.x);
17    }
18
19    Coord& operator+=(const Direction &other);
20
21    Coord operator+(const Direction &dir);
22    
23    int y = 0;
24    int x = 0;
25};
26
27
28class Direction {
29public:
30    void rotateRight() {
31        dirIndex = (dirIndex + 1) % 4;
32    }
33
34    void rotateLeft() {
35        dirIndex = (dirIndex + 4 - 1) % 4;
36    }
37
38    Coord getDirCoord() const {
39        return directions[dirIndex];
40    }
41
42private:
43    vector<Coord> directions{
44        Coord(1, 0),
45        Coord(0, 1),
46        Coord(-1, 0),
47        Coord(0, -1)
48    };
49
50    int dirIndex = 0;
51};
52
53Coord& Coord::operator+=(const Direction &other) {
54    *this += other.getDirCoord();
55    return *this;
56}
57
58Coord Coord::operator+(const Direction &dir) {
59    return *this + dir.getDirCoord();
60}
61
62class Solution {
63public:
64    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
65        unordered_map<int, unordered_set<int>> obstacleMap;
66
67        for (const vector<int> &obstacle : obstacles) {
68            obstacleMap[obstacle[1]].insert(obstacle[0]);
69        }
70
71        Coord pos;
72        Direction dir;
73
74        int res = 0;
75
76        for (int cmd : commands) {
77            if (cmd == -2) {
78                dir.rotateLeft();
79                continue;
80            } 
81
82            if (cmd == -1) {
83                dir.rotateRight();
84                continue;
85            }
86
87            for (int i = 1; i <= cmd; i++) {
88                if (
89                    obstacleMap.contains((pos + dir).y) &&
90                    obstacleMap[(pos + dir).y].contains((pos + dir).x)
91                ) {
92                    break;
93                }
94                pos += dir;
95            }
96
97            res = max(res, (int)pow(pos.x, 2) + (int)pow(pos.y, 2));
98        }
99
100        return res;
101    }
102};