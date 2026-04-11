// Last updated: 4/11/2026, 12:21:35 PM
1/* 
2Values are in pairs. 
3First value is the count. 
4Second value is the actual token. 
5
6Keep an index in the encoding. 
7Keep a counter of remaining count for that token. 
8Keep a store of that token. 
9 */
10class RLEIterator {
11public:
12    RLEIterator(vector<int>& encoding) : encoding_(encoding) {}
13    
14    int next(int n) {
15        int lastValue = 0;
16        for (int i = 0; i < n;) {
17            while (count == 0) {
18                if (index == encoding_.size()) {
19                    return -1;
20                }
21                count = encoding_[index];
22                index++;
23                token = encoding_[index];
24                index++;
25            }
26            int minJump = min(count, n-i);
27            count -= minJump;
28            i += minJump;
29
30            lastValue = token;
31        }
32
33        return lastValue;
34    }
35
36private:
37    int index = 0;
38    int count = 0;
39    int token;
40
41    vector<int> encoding_;
42};
43
44/**
45 * Your RLEIterator object will be instantiated and called as such:
46 * RLEIterator* obj = new RLEIterator(encoding);
47 * int param_1 = obj->next(n);
48 */