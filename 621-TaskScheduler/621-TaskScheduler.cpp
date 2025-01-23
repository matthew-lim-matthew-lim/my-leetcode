class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> char_map;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        priority_queue<pair<int, char>> pq2;
        for (char& c : tasks) {
            if (!char_map.contains(c)) pq.push({ - n - 1, c });
            char_map[c]++;
        }

        int res = 0;
        while (!char_map.empty()) {
            while (!pq.empty() && pq.top().first + n < res) {
                pair<int, char> curr = pq.top();
                pq.pop();
                pq2.push({ char_map[curr.second], curr.second });
            }

            if (!pq2.empty()) {
                // We can use this letter now
                pair<int, char> curr = pq2.top();
                pq2.pop();
                char_map[curr.second]--;
                if (char_map[curr.second] == 0) {
                    char_map.erase(curr.second);
                } else {
                    pq.push({ res, curr.second });
                }
            } 
            res++;
        }

        return res;
    }
};