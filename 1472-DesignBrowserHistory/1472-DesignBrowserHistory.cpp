// The back history is never cleared.
// The forward history is populated only when the back history is used. 
// The forward history should be a stack. When we go back, we push to the forward history stack. 
// The back history should also be a stack. When we go forward, we push to the back history stack. 
// This also avoids duplicate entries. 

class BrowserHistory {
private:
    stack<string> backHist;
    stack<string> forwardHist;
    string curr;
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        while (!forwardHist.empty()) {
            forwardHist.pop();
        }
        backHist.push(curr);
        curr = url;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps && !backHist.empty(); i++) {
            forwardHist.push(curr);
            curr = backHist.top();
            backHist.pop();
        }
        return curr;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps && !forwardHist.empty(); i++) {
            backHist.push(curr);
            curr = forwardHist.top();
            forwardHist.pop();
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */