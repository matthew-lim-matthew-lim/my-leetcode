// Last updated: 4/25/2026, 5:15:10 PM
1/* 
2unordered_map<int nums1Val, int count> nums1Count;
3- Use this to bulk update the number of totals, since each key
4for totals is `nums1Val + val`. 
5
6unordered_map<int total, int count> totals;
7
8add():
9- Decrement count of all the old totals.
10- Increment count of all the new totals. 
11 */
12class FindSumPairs {
13private:
14    unordered_map<int, int> nums1Count_;
15    unordered_map<int, int> totals_;
16
17    vector<int> nums2_;
18public:
19    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : 
20        nums2_(nums2) 
21    {
22        for (int val : nums1) {
23            nums1Count_[val]++;
24        }
25
26        for (int val : nums2_) {
27            for (const auto &p : nums1Count_) {
28                totals_[p.first + val] += p.second;
29            }
30        }
31    }
32    
33    void add(int index, int val) {
34        for (const auto &p : nums1Count_) {
35            totals_[p.first + nums2_[index]] -= p.second;
36        }
37
38        nums2_[index] += val;
39
40        for (const auto &p : nums1Count_) {
41            totals_[p.first + nums2_[index]] += p.second;
42        }
43    }
44    
45    int count(int tot) {
46        if (totals_.contains(tot)) {
47            return totals_[tot];
48        }
49        return 0;
50    }
51};
52
53/**
54 * Your FindSumPairs object will be instantiated and called as such:
55 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
56 * obj->add(index,val);
57 * int param_2 = obj->count(tot);
58 */