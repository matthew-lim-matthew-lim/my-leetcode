// Last updated: 3/30/2025, 12:29:55 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Map the count of each char over the whole string in a map.
        // Map the count of each char in the current partition.
        // If the count of every char in the current partition, in the whole string, is 0, then finish this partition.
        vector<int> sCharMap(26, 0);
        for (char c : s) {
            sCharMap[c - 'a']++;
        }

        // Now, start partitioning.
        vector<int> res;
        unordered_map<char, int> currPartChars;
        for (char c : s) {
            currPartChars[c]++;
            sCharMap[c - 'a']--;

            // Check that all the items in the multiset are not in the remaining char map
            bool validPartition = true;
            int partitionSize = 0;
            for (auto p : currPartChars) {
                if (sCharMap[p.first - 'a'] != 0) {
                    validPartition = false;
                    break;
                }
                partitionSize += p.second;
            } 
            if (validPartition) {
                res.push_back(partitionSize);
                currPartChars.clear();
            }
        }

        return res;
    }
};