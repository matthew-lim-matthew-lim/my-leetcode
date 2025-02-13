class TwoSum {
private:
    // Use a multiset since we need to maintain order on insertion, but we can also have multiple elements. 
    multiset<long long> numSet;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        numSet.insert(number);
    }
    
    bool find(int value) {
        for (long long num : numSet) {
            if (numSet.contains(value - num)) {
                if (num == value - num) {
                    return numSet.count(num) > 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */