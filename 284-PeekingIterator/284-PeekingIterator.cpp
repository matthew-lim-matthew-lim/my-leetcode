// Last updated: 4/5/2026, 8:57:41 PM
1/*
2 * Below is the interface for Iterator, which is already defined for you.
3 * **DO NOT** modify the interface for Iterator.
4 *
5 *  class Iterator {
6 *		struct Data;
7 * 		Data* data;
8 *  public:
9 *		Iterator(const vector<int>& nums);
10 * 		Iterator(const Iterator& iter);
11 *
12 * 		// Returns the next element in the iteration.
13 *		int next();
14 *
15 *		// Returns true if the iteration has more elements.
16 *		bool hasNext() const;
17 *	};
18 */
19
20class PeekingIterator : public Iterator {
21public:
22	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
23	    // Initialize any member here.
24	    // **DO NOT** save a copy of nums and manipulate it directly.
25	    // You should only use the Iterator interface methods.
26	    
27	}
28	
29    // Returns the next element in the iteration without advancing the iterator.
30	int peek() {
31        Iterator it(*this);
32
33        return it.next();
34	}
35	
36	// hasNext() and next() should behave the same as in the Iterator interface.
37	// Override them if needed.
38	// int next() {
39	    
40	// }
41	
42	// bool hasNext() const {
43	    
44	// }
45};