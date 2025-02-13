class TimeMap {
private:
    unordered_map<string, map<int, string>> timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = timeMap[key].rbegin();
        while (it != timeMap[key].rend() && it->first > timestamp) {
            it++;
        } 
        if (it == timeMap[key].rend()) {
            return "";
        }
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */