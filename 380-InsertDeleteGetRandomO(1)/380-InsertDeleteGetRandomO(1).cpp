class RandomizedSet {
private:
    // Unordered map records index in vector where the number is.
    unordered_map<int, int> indexMap;
    // When a number is removed, the value in the vector for that number points to the number at the end. 
    vector<int> values;
public:
    RandomizedSet() : values(200000, 0) {
        
    }
    
    bool insert(int val) {
        if (indexMap.contains(val)) {
            return false;
        } else {
            values[indexMap.size()] = val;
            indexMap[val] = indexMap.size();
            return true;
        }
    }
    
    bool remove(int val) {
        if (!indexMap.contains(val)) {
            return false;
        } else {
            values[indexMap[val]] = values[indexMap.size() - 1];
            indexMap[values[indexMap.size() - 1]] = indexMap[val];
            indexMap.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int index = rand() % indexMap.size();
        return values[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */