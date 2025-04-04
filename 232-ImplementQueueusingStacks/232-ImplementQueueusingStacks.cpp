// Last updated: 4/4/2025, 11:46:54 PM
class MyQueue {
private:
    stack<int> out;
    stack<int> in;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (!out.empty()) {
            int res = out.top();
            out.pop();
            return res;
        }
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
        int res = out.top();
        out.pop();
        return res;
    }
    
    int peek() {
        if (!out.empty()) {
            int res = out.top();
            return res;
        }
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
        int res = out.top();
        return res;
    }
    
    bool empty() {
        return (in.empty() && out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */