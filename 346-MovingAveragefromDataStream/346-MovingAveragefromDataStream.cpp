class MovingAverage {
private:
    int size;
    queue<int> q;
    int sum = 0;
public:
    MovingAverage(int size) : size(size) {
        
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() > size) {
            int front = q.front();
            q.pop();
            sum -= front;
        }
        return double(sum) / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */