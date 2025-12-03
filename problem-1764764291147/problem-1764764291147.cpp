// Last updated: 12/3/2025, 11:18:11 PM
1/*
2LOL
3Using hashmap this is easy.
4*/
5class Solution {
6public:
7    int getMirror(int val) {
8        int cpy = val;
9        int digits = 0;
10        while (cpy > 0) {
11            cpy /= 10;
12            digits++;
13        }
14
15        long long res = 0;
16        for (int i = 0; i <= digits; i++) {
17            res += (long long)pow(10, i - 1) * ((val / (long long)pow(10, digits - i)) % 10);
18        }
19        return res;
20    }
21    
22    int minMirrorPairDistance(vector<int>& nums) {
23        unordered_map<int, int> numMap;
24        int n = nums.size();
25        int minDis = n;
26        for (int i = n - 1; i >= 0; i--) {
27            if (numMap.contains(getMirror(nums[i]))) {
28                minDis = min(minDis, abs(i - numMap[getMirror(nums[i])]));
29            }
30            numMap[nums[i]] = i;
31        }
32        
33        return n == minDis ? -1 : minDis;
34    }
35};