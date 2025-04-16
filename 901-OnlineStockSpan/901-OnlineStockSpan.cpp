// Last updated: 4/16/2025, 2:10:36 PM
class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        vals.push_back(price);
        if(current.empty())
        {
            current.push_back(days++);

            return 1;
        }

        while(!current.empty() && vals[current.back()] <= price)
        {
            current.pop_back();
        }
        int ret = current.empty() ? days + 1 : days - current.back();
        current.push_back(days++);
        return ret;

    }
    // 100 -> 1, 80 -> 1 (1 - 0), 60 -> 1, 70 (3 - 1)
    // 60 -> 1 (4 - 3), 75, 5 - 1
    // 31 -> 1, 41 
    int days = 0;
    vector<int> current; // take indices
    vector<int> vals;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */