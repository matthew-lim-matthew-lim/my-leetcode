// Last updated: 3/22/2025, 3:22:11 PM
class AllOne {
public:
// UnorderedMap from { IndexValue } to { std::list iter, int count } of the first element of that value.

    // unordered_map allows us to know which element to remove. 
    unordered_map<string, int> keyToCount;

    // Using unordered_set allows us to add/remove elements from each count group in O(1)
    // This problem is made easier because every time we add a new key, it is always count 1. 
    unordered_map<int, list<unordered_set<string>>::iterator> countToKeys;

    // Using std::list allows us get the max and min in O(1).
    // It also allows us to increment and decrement in O(1). 
    list<unordered_set<string>> stringSets;

    AllOne() {
    }
    
    void inc(string key) {
        if (!keyToCount.contains(key)) {
            // This is a new element.
            keyToCount[key] = 1;
            if (countToKeys.contains(1)) {
                // Insert the key into the unordered_set of elements with count 1.
                countToKeys[1]->insert(key);
            } else {
                // Make an unordered_set with elements with count 1.
                // It will always be at the front. 
                stringSets.emplace_front(unordered_set<string>{ key });
                countToKeys[1] = stringSets.begin();
            }
        } else {
            // This element already exists.
            int oldCount = keyToCount[key];
            keyToCount[key]++;

            // It should be true that countToKeys.contains(oldCount)

            // Remove the element from that count.
            list<unordered_set<string>>::iterator it = countToKeys[oldCount];
            it->erase(key);

            // If empty, remove this set
            if (it->empty()) {
                // We can do this since the erasure of it will assign the LHS with the element AFTER it.
                it = stringSets.erase(it);
                countToKeys.erase(oldCount);
            } else {
                // Otherwise, still need to move it rightwards (double entendre). 
                it++;
            }
            if (it == stringSets.end() || keyToCount[*(it->begin())] != oldCount + 1) {
                // Need to make a new set.
                stringSets.insert(it, unordered_set<string>{ key });
                it--;
                countToKeys[oldCount + 1] = it;
            } else {
                // Don't need to make a new set.
                it->insert(key);
            }
        }
    }
    
    void dec(string key) {
        // It is guaranteed that key exists in the data structure before the decrement. 

        // This element already exists.
        int oldCount = keyToCount[key];
        keyToCount[key]--;

        if (keyToCount[key] == 0) {
            // This element is to be removed
            list<unordered_set<string>>::iterator it = countToKeys[1];
            it->erase(key);
            keyToCount.erase(key);
            if (it->empty()) {
                // Erase the set
                it = stringSets.erase(it);
                countToKeys.erase(1);
            }
        } else {
            // This element is to be kept
            // Need to erase it from the old set and add it to the new set.
            list<unordered_set<string>>::iterator it = countToKeys[oldCount];
            it->erase(key);
            keyToCount[key] = oldCount - 1;
            if (it->empty()) {
                // Erase the set
                it = stringSets.erase(it);
                countToKeys.erase(oldCount);
            }
            // Check if the key before exists
            if (it == stringSets.begin() || keyToCount[*(prev(it)->begin())] != oldCount - 1) {
                // This element doesnt already exist. Make the new element.  
                stringSets.insert(it, unordered_set<string>{ key });
                it--;
                countToKeys[oldCount - 1] = it;
            } else {
                // This element already exists.
                it--;
                it->insert(key);
            }
        }
    }
    
    string getMaxKey() {
        if (keyToCount.empty()) {
            return "";
        }
        return *(stringSets.rbegin()->begin());
    }
    
    string getMinKey() {
        if (keyToCount.empty()) {
            return "";
        }
        return *(stringSets.begin()->begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */