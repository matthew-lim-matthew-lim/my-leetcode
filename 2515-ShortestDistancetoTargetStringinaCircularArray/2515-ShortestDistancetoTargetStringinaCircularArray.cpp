// Last updated: 4/15/2026, 4:44:46 PM
1/* 
2L->R: R - L
3
4--L R<-: L + (words.size() - R) 
5 */
6
7class Solution {
8public:
9    int closestTarget(vector<string>& words, string target, int startIndex) {
10        for (int i = 0; i < words.size(); i++) {
11            if (words[(startIndex + i) % words.size()] == target) {
12                return i;
13            }
14            if (words[(words.size() + startIndex - i) % words.size()] == target) {
15                return i;
16            }
17        }
18        
19        return -1;
20    }
21};