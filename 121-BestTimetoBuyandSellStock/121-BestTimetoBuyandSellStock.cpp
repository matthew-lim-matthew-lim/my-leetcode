// Last updated: 11/30/2025, 4:10:17 PM
1/* 
2Traverse backwards. 
3Keep track of the biggest number.
4When you reach a bigger number, update it. 
5Track the biggest difference. 
6 */
7class Solution {
8public:
9    int maxProfit(vector<int>& prices) {
10        int n = prices.size();
11        int currLargest = prices.back();
12        int biggestDiff = 0;
13        for (int i = n - 1; i >= 0; i--) {
14            if (prices[i] > currLargest) {
15                currLargest = prices[i];
16            }
17            if (currLargest - prices[i] > biggestDiff) {
18                biggestDiff = currLargest - prices[i];
19            }
20        }
21
22        return biggestDiff;
23    }
24};