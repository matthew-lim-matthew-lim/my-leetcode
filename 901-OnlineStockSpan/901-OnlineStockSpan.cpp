// Last updated: 4/16/2025, 1:52:02 PM
class StockSpanner {
private:
    vector<int> stockPrices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        stockPrices.push_back(price);

        int n = stockPrices.size();

        for (int i = n - 1; i >= 0; i--) {
            if (stockPrices[i] > price) {
                return (n - 1) - i;
            }
        }

        return n;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */