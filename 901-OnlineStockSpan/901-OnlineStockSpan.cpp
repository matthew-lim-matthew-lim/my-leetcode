// Last updated: 4/16/2025, 2:01:22 PM
class StockSpanner {
private:
// For each entry, keep track of their span, so we can skip over some checking
    vector<pair<int, int>> stockPrices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        stockPrices.push_back({ 1, price });

        int n = stockPrices.size();

        int i = n - 1;
        while (i >= 0) {
            if (stockPrices[i].second > price) {
                stockPrices.back().first = (n - 1) - i;
                return (n - 1) - i;
            } else {
                i -= stockPrices[i].first;
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