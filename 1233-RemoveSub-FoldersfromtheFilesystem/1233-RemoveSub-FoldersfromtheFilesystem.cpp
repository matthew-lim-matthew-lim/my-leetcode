// Last updated: 7/19/2025, 3:24:58 PM
/* 
Sort 'folder'. 

If the first one is a prefix of the second one, skip it.
If the first one is not a prefix, include the second one and make it the first one again.
 */
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        
        vector<string> res;

        string match = folder.front();
        res.push_back(match);
        for (string &dir : folder) {
            if ((dir.find(match) != 0) || (dir.find(match) == 0 && dir.size() > match.size() && dir[match.size()] != '/')) {
                match = dir;
                res.push_back(dir);
            }
        }

        return res;
    }
};