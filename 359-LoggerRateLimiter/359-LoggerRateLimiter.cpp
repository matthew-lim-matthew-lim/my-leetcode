class Logger {
private:
    int lastPrint = -10;
    unordered_map<string, int> limiter;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!limiter.contains(message) || limiter[message] + 10 <= timestamp) {
            limiter[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */