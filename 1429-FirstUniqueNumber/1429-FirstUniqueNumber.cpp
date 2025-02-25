class FirstUnique {
public:
    queue<int> q;
    unordered_map<int, int> numMap;
    FirstUnique(vector<int>& nums) {
        // Simply use a map to store the quantities of each value. 
        for (int num : nums) {
            q.push(num);
            numMap[num]++;
        }
    }
    
    int showFirstUnique() {
        while (!q.empty() && numMap[q.front()] > 1) {
            q.pop();
        }
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        q.push(value);
        numMap[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */