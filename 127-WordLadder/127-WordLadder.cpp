// Last updated: 7/21/2025, 11:14:21 PM
/* 
BFS.
 */
class Solution {
public:
    bool validWord(string &a, string &b) {
        int different = 0;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                different++;
            }
        }

        return different == 1;
    }

struct Step {
    string word;
    int lvl;
};

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<Step> q;

        q.push(Step(beginWord, 1));

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            Step curr = q.front();
            q.pop();
            string currWord = curr.word;
            int currLvl = curr.lvl;

            if (currWord == endWord) {
                return currLvl;
            }

            for (string &s : wordList) {
                if (!validWord(currWord, s) || visited.contains(s)) {
                    continue;
                }

                q.push(Step(s, currLvl + 1));
                visited.insert(s);
            }
        }

        return 0;
    }
};