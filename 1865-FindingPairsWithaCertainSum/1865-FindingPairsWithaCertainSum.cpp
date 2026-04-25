// Last updated: 4/25/2026, 5:21:06 PM
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
14    unordered_map<int, int> nums2Count_;
15    vector<int> nums1_;
16    vector<int> nums2_;
17public:
18    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : 
19        nums1_(nums1),
20        nums2_(nums2) 
21    {
22        for (int val : nums2) {
23            nums2Count_[val]++;
24        }
25    }
26    
27    void add(int index, int val) {
28        nums2Count_[nums2_[index]]--;
29        nums2_[index] += val;
30        nums2Count_[nums2_[index]]++;
31    }
32    
33    int count(int tot) {
34        int res = 0;
35
36        for (int val : nums1_) {
37            int rem = tot - val;
38            if (nums2Count_.contains(rem)) {
39                res += nums2Count_[rem];
40            }
41        }
42
43        return res;
44    }
45};
46
47/**
48 * Your FindSumPairs object will be instantiated and called as such:
49 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
50 * obj->add(index,val);
51 * int param_2 = obj->count(tot);
52 */