// Last updated: 5/2/2025, 5:14:51 PM
class Solution {
public:
    // Day 183 of LC daily
    // Reminds me of asteroid collisions.
    // Just failed the Optiver final interviews (system design, psuedocode, behavioural) I'm very sad.
    // Felt like they didnt fw me from the first interview today.
    // Still gonna code because one day hopefully I'll make it.
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        // Maybe I'll use dynamic programming, I miss it.
        vector<int> distL(n, INT_MAX);
        int d = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                d = 0;
            } else if (dominoes[i] == 'R') {
                d = INT_MAX;
            } else if (d < INT_MAX) {
                d++;
            }
            distL[i] = d;
        }

        vector<int> distR(n);
        d = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                d = 0;
            } else if (dominoes[i] == 'L') {
                d = INT_MAX;
            } else if (d < INT_MAX) {
                d++;
            }
            distR[i] = d;
        }

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') {
                if (distR[i] < distL[i]) {
                    dominoes[i] = 'R';
                } else if (distR[i] > distL[i]) {
                    dominoes[i] = 'L';
                }
            }
        }

        return dominoes;
    }
};