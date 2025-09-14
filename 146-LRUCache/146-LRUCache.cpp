// Last updated: 9/14/2025, 8:46:08 PM
/* 
Use a LL. 
When a key is used, move the node to the front. 
 */
class LRUCache {
private:

class ListItem {
public:
    int key;
    int val;
};

    int remainingCapacity_;
    list<ListItem> LL;
    unordered_map<int, list<ListItem>::iterator> itemMap;
public:
    LRUCache(int capacity) : remainingCapacity_(capacity) {
    }
    
    int get(int key) {
        if (!itemMap.contains(key)) {
            return -1;
        }

        list<ListItem>::iterator itr = itemMap[key];
        int val = itr->val;
        LL.push_back(ListItem(itr->key, itr->val));
        itemMap[key] = --LL.end();
        LL.erase(itr);
        return val;
    }
    
    void put(int key, int value) {
        if (itemMap.contains(key)) {
            list<ListItem>::iterator itr = itemMap[key];
            LL.push_back(ListItem(itr->key, value));
            itemMap[key] = --LL.end();
            LL.erase(itr);
            return;
        }

        if (remainingCapacity_ == 0) {
            itemMap.erase(LL.begin()->key);
            LL.pop_front();
        } else {
            remainingCapacity_--;
        }

        LL.push_back(ListItem(key, value));
        itemMap[key] = --LL.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */