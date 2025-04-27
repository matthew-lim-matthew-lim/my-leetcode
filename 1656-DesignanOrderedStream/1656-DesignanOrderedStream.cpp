// Last updated: 4/27/2025, 6:28:50 PM
class OrderedStream {
private:
    vector<string> valMap;
    int currIndex = 0;
public:
    OrderedStream(int n) : valMap(n) {}
    
    vector<string> insert(int idKey, string value) {
        valMap[idKey - 1] = value;
        vector<string> res;
        while (currIndex < valMap.size() && !valMap[currIndex].empty()) {
            res.push_back(valMap[currIndex]);
            currIndex++;
        }

        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */