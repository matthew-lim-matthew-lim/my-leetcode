// Last updated: 4/10/2026, 3:06:10 PM
1/* 
2Have a set. 
3The set is of the next number you want to use.
4When you `addBack()` a number, push it into the set. 
5Then, when you popSmallest, get the next smallest number in the set, and use that.
6If the set is empty, re-add into the set, the number you just used plus 1. 
7 */
8class SmallestInfiniteSet {
9public:
10    SmallestInfiniteSet() {}
11    
12    int popSmallest() {
13        if (!availNumbers.empty()) {
14            int res = *availNumbers.begin();
15            availNumbers.erase(res);
16            return res;
17        }
18        return nextNumber++;
19    }
20    
21    void addBack(int num) {
22        if (num < nextNumber) {
23            availNumbers.insert(num);
24        }
25    }
26private:
27    set<int> availNumbers;
28    int nextNumber = 1;
29};
30
31/**
32 * Your SmallestInfiniteSet object will be instantiated and called as such:
33 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
34 * int param_1 = obj->popSmallest();
35 * obj->addBack(num);
36 */