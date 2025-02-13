class DataStream {
private:
    int value_;
    int k_;
    int equalCount = 0;

public:
    DataStream(int value, int k) {
        value_ = value;
        k_ = k;
    }
    
    bool consec(int num) {
        if (num == value_) {
            equalCount++;
        } else {
            equalCount = 0;
        }
        return equalCount >= k_;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */