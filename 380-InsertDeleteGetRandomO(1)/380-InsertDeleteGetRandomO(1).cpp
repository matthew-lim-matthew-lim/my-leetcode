// Last updated: 9/24/2025, 6:55:37 PM
/* 
UnorderedMap {{ val, index }}
Vector [ val ]

If a value is removed, it is replaced with the last item in the vector, and the vector size is decremented. 
If a value is added, it is appended to the end of the vector.
 */
class RandomizedSet {
private:
    vector<int> vec;
    unordered_map<int, int> itemMap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (itemMap.contains(val)) {
            return false;
        }
        itemMap[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!itemMap.contains(val)) {
            return false;
        }
        itemMap[vec[vec.size() - 1]] = itemMap[val];
        vec[itemMap[val]] = vec[vec.size() - 1];
        vec.pop_back();
        itemMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */