class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict{wordDict.begin(), wordDict.end()};

        // Iterate through the string s, adding letters one by one. 
        // Let k be the current string.
        // Let w be a particular word in wordDict. Loop through all the words in wordDict.
        // dp(k) = dp(k - w)
        // Would be like unordered_set.contains(k - w).
        
        string k;
        for (int i = 0; i < s.size(); i++) {
            k.push_back(s[i]);
            for (string& w : wordDict) {
                // Check if k ends with w
                if (k.size() >= w.size() && k.compare(k.size() - w.size(), w.size(), w) == 0) {
                    // Compute k - w
                    string kMinusW = k.substr(0, k.size() - w.size());
                    // Check if k - w is in the set
                    if (dict.contains(kMinusW)) {
                        dict.insert(k);
                    }
                }
            }
        }

        return dict.contains(s);
    }
};