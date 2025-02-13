class StockPrice {
private:
    unordered_map<int, int> priceMap;
    map<int, int> priceCount;
    int lastPrice;
    int lastTimestamp;

public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (timestamp >= lastTimestamp) {
            lastTimestamp = timestamp;
            lastPrice = price;
        }
        if (priceMap.contains(timestamp)) {
            priceCount[priceMap[timestamp]]--;
            if (priceCount[priceMap[timestamp]] == 0) {
                priceCount.erase(priceMap[timestamp]);
            }
        }
        priceMap[timestamp] = price;
        priceCount[priceMap[timestamp]]++;
    }
    
    int current() {
        return lastPrice;
    }
    
    int maximum() {
        return priceCount.rbegin()->first;
    }
    
    int minimum() {
        return priceCount.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */