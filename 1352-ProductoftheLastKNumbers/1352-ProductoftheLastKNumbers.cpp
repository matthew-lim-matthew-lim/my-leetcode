class ProductOfNumbers {
private:
    vector<int> currProd;
    vector<int> distZero;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        // cout << "num: " << num << endl;
        if (num == 0) {
            currProd.push_back(1);
            distZero.push_back(0);
        } else if (currProd.size() == 0) {
            currProd.push_back(num);
            distZero.push_back(1);
        } else {
            cout << currProd.back() << endl;
            currProd.push_back(num * currProd.back());
            distZero.push_back(distZero.back() + 1);
        }
    }
    
    int getProduct(int k) {
        // cout << "currProd values" << endl;
        // for (int v : currProd) {
        //     cout << v << " ";
        // }
        // cout << endl;
        // cout << "distZero values" << endl;
        // for (int v : distZero) {
        //     cout << v << " ";
        // }
        // cout << endl;
        // cout << "k: " << k << endl;
        // cout << "distZero.back(): " << distZero.back() << endl;
        if (k > distZero.back()) {
            return 0;
        } else {
            if ((static_cast<int>(currProd.size()) - 1) - k >= 0) {
                return currProd.back() / currProd[(currProd.size() - 1) - k];
            } else {
                return currProd.back();
            }
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */