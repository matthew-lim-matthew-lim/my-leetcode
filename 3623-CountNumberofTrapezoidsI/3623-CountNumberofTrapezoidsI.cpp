// Last updated: 12/2/2025, 10:09:44 PM
1/* 
2V1:
3
4A trapezoid is any 4-sided shape with at least 1 pair of parallel sides.
5
6(p1x - p2x)/(p3x - p4x) == k
7(p1y - p2y)/(p3y - p4y) == k
8
9pick point 1.
10pick point 2.
11pick point 3.
12point 4 must be k*(p1-p2).
13
14V2:
15
16Calculate all the lines we can create with 2 points.
17
18Make any segment into the simplest ratio like 2/4 becomes 1/2.
19
20For every pair, add +1 to result. 
21
22For every identical pair (like 1/2 and 1/2 in original form), use some mechanism to stop double count. 
23
24edges data structure:
25for a vector (x, y).
26
27edges[x/gcd(x,y)]][y/gcd(x,y)][x] = countofexactly(x,y).
28
29Then,
30
311countofexaclty(x,y) * 1countofexactly(x,y) // For same pairs, keep the same.
32
331countofexaclty(x,y) * 2countofexactly(x,y) * 2 // For different pairs, double them.
34 */
35
36class Solution {
37public:
38    int countTrapezoids(vector<vector<int>>& points) {
39        // The problem asks for HORIZONTAL trapezoids.
40        // A horizontal trapezoid has at least one pair of parallel sides parallel to the x-axis.
41        // This implies we need to select 4 points such that 2 points share a y-coordinate (forming one base)
42        // and the other 2 points share a different y-coordinate (forming the other base).
43        
44        // Step 1: Count points at each y-coordinate.
45        unordered_map<int, int> y_counts;
46        for (const auto& p : points) {
47            y_counts[p[1]]++;
48        }
49
50        long long total_trapezoids = 0;
51        long long running_segments_sum = 0; // Sum of segment counts from previous levels
52        long long MOD = 1e9 + 7;
53
54        // Step 2: Calculate segments at each level and combine with previous levels.
55        // If a level has 'k' points, we can form C(k, 2) horizontal segments.
56        // If we have 'S_new' segments at the current level and 'S_old_sum' accumulated from previous levels,
57        // we can form S_new * S_old_sum trapezoids.
58        // This effectively calculates sum(S_i * S_j) for all i < j.
59        
60        for (auto const& [y, count] : y_counts) {
61            if (count < 2) continue; // Need at least 2 points to form a segment
62            
63            // Number of ways to choose 2 points from 'count' points: k * (k - 1) / 2
64            long long current_segments = (long long)count * (count - 1) / 2;
65            
66            // We work with modulo arithmetic for the answer
67            long long seg_mod = current_segments % MOD;
68            
69            // Add combinations with all previous levels
70            // current_segments * (sum of all previous segments)
71            total_trapezoids = (total_trapezoids + seg_mod * running_segments_sum) % MOD;
72            
73            // Add current level's segments to the running sum for future levels
74            running_segments_sum = (running_segments_sum + seg_mod) % MOD;
75        }
76
77        return (int)total_trapezoids;
78    }
79};