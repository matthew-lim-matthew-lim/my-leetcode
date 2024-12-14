class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Monotonic Stack

        // Initialise a result array with the unsuccessful result as the default value.
        vector<int> res(temperatures.size(), 0);

        // Keep a stack built from right to left.
        // This stack will be monotonically decreasing (since it is right to left).
        stack<vector<int>> stk;

        reverse(temperatures.begin(), temperatures.end());

        for (int i = 0; i < temperatures.size(); i++) {
            // While the element to be added is bigger than top of stack, pop the top of the stack. Also, 
            // pop_back() the end of the indices vector for that map entry.  
            // This keep the stack monotonically decreasing.
            // For example in example 1: [73,74,75,71,69,72,76,73]
            // When we reach 75, we will pop 69, 72, which gives us 76 at the top of stack. If later in the array,
            // we find a value that is less than 69 and 72, that value will have the 75 (that causes 69 and 72 to pop)
            // as it's next largest (hence the pop-ing is appropriate).
            while (!stk.empty() && stk.top()[0] <= temperatures[i]) {
                stk.pop();
            }
            
            // If the stack is non-empty, then the next greatest for the current value is the current top of the stack. 
            if (!stk.empty()) {
                // Since we reversed the array, we need to adjust the indicies that we use.
                res[temperatures.size() - 1 - i] = abs(stk.top()[1] - i);
            }

            stk.push({temperatures[i], i});
        }

        return res;
    }
};