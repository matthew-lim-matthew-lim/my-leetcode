class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Prefix min, and Suffix max.
        vector<int> pre_min(prices.size(), prices[0]);
        vector<int> suf_max(prices.size(), prices[prices.size() - 1]);
        for (int i = 1; i < prices.size(); i++) {
            pre_min[i] = min(prices[i], pre_min[i - 1]);
        }
        for (int i = prices.size() - 2; i >= 0; i--) {
            suf_max[i] = max(prices[i], suf_max[i + 1]);
        }

        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            max_profit = max(max_profit, suf_max[i] - pre_min[i - 1]);
        }

        return max_profit;
    }
};