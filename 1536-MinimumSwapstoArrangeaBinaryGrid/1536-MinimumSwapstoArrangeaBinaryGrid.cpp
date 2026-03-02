// Last updated: 3/2/2026, 9:26:16 PM
1/* 
2Top one needs to have 0's from index 1 to the end.
32nd top one needs to have 0's from index 2 to the end.
43rd top one needs to have 0's from index 3 to the end.
5etc. 
6
7Just swap the closest one to the top that satisfies the 1st condition, up to position 1.
8Swap the closest one to the top that satisfies the 2nd condition, up to position 2.
9Swap the closest one to the top that satisfies the 3rd condition, up to position 3.
10
11Just sort the rows from most 0's to least 0's.
12 */
13class Solution {
14public:
15    int minSwaps(vector<vector<int>>& grid) {
16        vector<int> smallGrid;
17        int n = grid.size(); 
18        for (const vector<int> &vec : grid) {
19            int i = n - 1;
20            for (; i >= 0; i--) {
21                if (vec[i] == 1) {
22                    break;
23                }
24            }
25            // Want to push back the index of the first '1'. 
26            smallGrid.push_back(i);
27        }
28
29        int res = 0;
30        for (int i = 0; i < n - 1; i++) {
31            if (smallGrid[i] > i) {
32                // cout << "found: " << i << endl;
33                // Find a swap partner
34                int swapPartner = -1;
35                for (int j = i + 1; j < n; j++) {
36                    if (smallGrid[j] <= i) {
37                        swapPartner = j;
38                        break;
39                    }
40                }
41
42                if (swapPartner == -1) {
43                    return -1;
44                }
45
46                for (int j = swapPartner; swapPartner > i; swapPartner--) {
47                    swap(smallGrid[swapPartner], smallGrid[swapPartner - 1]);
48                    res++;
49                }
50            }
51        }
52
53        // for (int i = 0; i < n; i++) {
54        //     cout << smallGrid[i] << endl;
55        // }
56
57        return res;
58    }
59};