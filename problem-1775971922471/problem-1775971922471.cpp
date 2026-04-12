// Last updated: 4/12/2026, 3:32:02 PM
1/*
2Troll Question.
3
4Need to make sure:
5- a + b <= c
6
7Then, to find angles, can do Cosine rule.
8- c^2 = a^2 + b^2 -2ab*CosC
9*/
10class Solution {
11public:
12    double findAngle(double a, double b, double c) {
13        double cosC = (a*a + b*b - c*c) / (2 * a * b);
14
15        double angleC_rad = std::acos(cosC);
16        return angleC_rad * (180.0 / M_PI);
17    }
18    
19    vector<double> internalAngles(vector<int>& sides) {
20        sort(sides.begin(), sides.end());
21        int a = sides[0];
22        int b = sides[1];
23        int c = sides[2];
24
25        if (a + b <= c) {
26            return {};
27        }
28
29        vector<double> res;
30
31        res.push_back(findAngle(a, b, c));
32        res.push_back(findAngle(b, c, a));
33        res.push_back(findAngle(c, a, b));
34
35        sort(res.begin(), res.end());
36
37        return res;
38    }
39};