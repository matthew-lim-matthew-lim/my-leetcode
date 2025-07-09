// Last updated: 7/10/2025, 12:43:26 AM
class LRUCache {

struct LLEntry {
    int key;
    int val;
};

private:
    int capacity_;
    list<LLEntry> LL;
    unordered_map<int, list<LLEntry>::iterator> LLMap;
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if (!LLMap.contains(key)) {
            return -1;
        }
        int value = LLMap[key]->val;
        LL.erase(LLMap[key]);
        LLMap[key] = LL.insert(LL.end(), LLEntry(key, value));
        return value;
    }
    
    void put(int key, int value) {
        if (LLMap.contains(key)) {
            LL.erase(LLMap[key]);
            LLMap[key] = LL.insert(LL.end(), LLEntry(key, value));
            return;
        }
        LLMap[key] = LL.insert(LL.end(), LLEntry(key, value));
        if (capacity_ > 0) {
            capacity_--;
        } else {
            LLMap.erase(LL.begin()->key);
            LL.erase(LL.begin());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */