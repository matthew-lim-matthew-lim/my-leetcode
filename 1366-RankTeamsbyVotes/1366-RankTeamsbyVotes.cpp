class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // For each position, count the number of votes for each letter.
        int nCandidates = votes[0].size(); 
        vector<vector<int>> voteCount(26, vector<int>(nCandidates, nCandidates));
        
        for (string &vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                voteCount[vote[i] - 'A'][i]--;
            }
        }

        // Maybe use a vector to represent it all, and get it sorted.
        // vector = { 1st pos, 2nd pos, ... , last pos, char represented as int };
        // Just use the nCandidates - votes, so we can sort in ascending order.
        for (int i = 0; i < voteCount.size(); i++) {
            voteCount[i].push_back(i);
        }
        sort(voteCount.begin(), voteCount.end());
        
        string res;
        for (int i = 0; i < nCandidates; i++) {
            res += voteCount[i].back() + 'A';
        }

        return res;
    }
};