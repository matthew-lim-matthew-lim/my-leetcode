// Last updated: 9/15/2025, 6:59:39 PM
/* 
Map, then a priority queue.
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> count;
        for (int &num : nums) {
            count[num]++;
        }

        multimap<int, int> ordered_map;
        for (pair<const int, int> &p : count) {
            ordered_map.insert({p.second, p.first});
        }

        map<int, int>::reverse_iterator it = ordered_map.rbegin();
        for (int i = 0; i < k; i++) {
            res.push_back(it->second);
            it++;
        }

        return res;
    }
};