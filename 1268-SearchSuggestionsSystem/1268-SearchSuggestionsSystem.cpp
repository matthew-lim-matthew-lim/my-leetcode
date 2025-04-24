// Last updated: 4/24/2025, 10:14:46 PM
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;

        sort(products.begin(), products.end());

        for (int i = 1; i <= searchWord.size(); ++i) {
            string prefix = searchWord.substr(0, i);
            vector<string> matches;

            for (const string& product : products) {
                if (product.starts_with(prefix)) {
                    matches.push_back(product);
                    if (matches.size() == 3) break; 
                }
            }

            res.push_back(matches);
        }

        return res;
    }
};
