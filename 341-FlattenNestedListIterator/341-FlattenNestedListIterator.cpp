// Last updated: 4/15/2026, 3:45:44 PM
1/**
2 * // This is the interface that allows for creating nested lists.
3 * // You should not implement it, or speculate about its implementation
4 * class NestedInteger {
5 *   public:
6 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
7 *     bool isInteger() const;
8 *
9 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
10 *     // The result is undefined if this NestedInteger holds a nested list
11 *     int getInteger() const;
12 *
13 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
14 *     // The result is undefined if this NestedInteger holds a single integer
15 *     const vector<NestedInteger> &getList() const;
16 * };
17 */
18
19class NestedIterator {
20public:
21    NestedIterator(vector<NestedInteger> &nestedList) : 
22        nestedList_(nestedList), 
23        stk_({IterPair{nestedList.begin(), nestedList.end()}})
24    {
25    }
26    
27    int next() {
28        while (!stk_.top().iter->isInteger()) {
29            stk_.push(IterPair{stk_.top().iter->getList().begin(), stk_.top().iter->getList().end()}); 
30        }
31
32        int val = stk_.top().iter->getInteger();
33        stk_.top().iter++;
34        while (!stk_.empty() && stk_.top().iter == stk_.top().endIter) {
35            stk_.pop();
36            if (!stk_.empty()) stk_.top().iter++;
37        }
38
39        return val;
40    }
41    
42    bool hasNext() {
43        if (stk_.empty()) return false;
44
45        while (!stk_.empty() && !stk_.top().iter->isInteger()) {
46            while (stk_.top().iter != stk_.top().endIter && !stk_.top().iter->isInteger()) {
47                stk_.push(IterPair{stk_.top().iter->getList().begin(), stk_.top().iter->getList().end()}); 
48            }
49            while (!stk_.empty() && stk_.top().iter == stk_.top().endIter) {
50                stk_.pop();
51                if (!stk_.empty()) stk_.top().iter++;
52            }
53        }
54
55        return !stk_.empty();
56    }
57private:
58    struct IterPair {
59        vector<NestedInteger>::iterator iter;
60        vector<NestedInteger>::iterator endIter;
61    };
62
63    stack<IterPair> stk_;
64    vector<NestedInteger> nestedList_;
65};
66
67/**
68 * Your NestedIterator object will be instantiated and called as such:
69 * NestedIterator i(nestedList);
70 * while (i.hasNext()) cout << i.next();
71 */