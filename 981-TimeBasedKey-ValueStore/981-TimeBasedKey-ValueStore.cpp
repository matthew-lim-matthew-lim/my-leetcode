// Last updated: 4/25/2025, 3:12:58 AM
class TimeMap {
private:
    struct Entry {
        int timestamp;
        string value;
    };

    unordered_map<string, vector<Entry>> entryMap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        entryMap[key].push_back(Entry{ timestamp, value });
    }

    string binarySearch(vector<Entry> &entries, int timestamp) {
        int lo = 0;
        int hi = entries.size() - 1;
        int bestSoFar = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (entries[mid].timestamp <= timestamp) {
                bestSoFar = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return bestSoFar == -1 ? "" : entries[bestSoFar].value;
    }

    string get(string key, int timestamp) {
        return binarySearch(entryMap[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */