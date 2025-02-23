class MRUQueue {
public:
    vector<int> vec;
    MRUQueue(int n) {
        // Do it faster with a doubly linked list. 
        vec = vector(n, 0);
        for (int i = 0; i < n; i++) {
            vec[i] = i + 1;
        }
    }
    
    int fetch(int k) {
        int num = vec[k - 1];
        vec.erase(vec.begin() + k - 1);
        vec.push_back(num);
        return num;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */