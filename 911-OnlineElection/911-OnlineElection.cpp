// Last updated: 4/12/2026, 5:35:42 PM
1/* 
2At each time entry in the vector, have the id of the person with the most number of votes. 
3
4unordered_map<PersonId, Votes> 
5
6int mostVotes;
7 */
8using PersonId = int;
9using Votes = int;
10
11class TopVotedCandidate {
12public:
13    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
14        unordered_map<PersonId, Votes> votesMap;
15        int mostVotes = 0;
16        int mostVoted = 0;
17
18        int n = persons.size();
19
20        for (int i = 0; i < n; i++) {
21            votesMap[persons[i]]++;
22            if (votesMap[persons[i]] >= mostVotes) {
23                mostVotes = votesMap[persons[i]];
24                mostVoted = persons[i];
25            }
26
27            bestPersons.push_back({
28                times[i],
29                mostVoted
30            });
31        }
32    }
33    
34    int q(int t) {
35        auto it = std::upper_bound(bestPersons.begin(), bestPersons.end(), t, 
36            [](int time, const vector<int>& p) {
37                return time < p[0];
38            });
39        
40        if (it != bestPersons.begin()) {
41            it--;
42            return (*it)[1];
43        }
44
45        return -1;
46    }
47
48private:
49    vector<vector<int>> bestPersons;
50};
51
52/**
53 * Your TopVotedCandidate object will be instantiated and called as such:
54 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
55 * int param_1 = obj->q(t);
56 */