// Last updated: 3/1/2026, 12:32:21 PM
1/* 
2There is n <= 30.
3
4Any pair is either matched or unmatched. 
5Every 2 people must be a couple, otherwise they are unmatched. 
6
7[0, 1, 3, 4, 2, 5]
8
9Is there one where the first swap is not the smart play?
10
11[0, 5, 3, 4, 1, 2]
12[0, 1, 3, 4, 5, 2]
13[0, 1, 3, 2, 5, 4]
14
15If the number x is even, the next number in the pair should be x+1. 
16If the number x is odd, the next number in the pair should x-1.
17 */
18class Solution {
19public:
20    int minSwapsCouples(vector<int>& row) {
21        int n = row.size();
22
23        vector<int> numToIndex(n);
24        for (int i = 0; i < n; i++) {
25            numToIndex[row[i]] = i;
26        }
27
28        int res = 0;
29
30        for (int i = 0; i < n; i += 2) {
31            if (row[i] % 2 == 0) {
32                if (row[i+1] == row[i] + 1) {
33                    continue;
34                }
35                int neededIndex = numToIndex[row[i]+1];
36                numToIndex[row[i]+1] = i+1;
37                numToIndex[row[i+1]] = neededIndex;
38                swap(row[i+1], row[neededIndex]);
39                res++;
40            } else {
41                if (row[i+1] == row[i] - 1) {
42                    continue;
43                }
44                int neededIndex = numToIndex[row[i]-1];
45                numToIndex[row[i]-1] = i+1;
46                numToIndex[row[i+1]] = neededIndex;
47                swap(row[i+1], row[neededIndex]);
48                res++;
49            }
50        }
51
52        return res;
53    }
54};