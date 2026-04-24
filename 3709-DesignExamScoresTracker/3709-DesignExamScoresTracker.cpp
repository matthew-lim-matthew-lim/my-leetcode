// Last updated: 4/24/2026, 9:07:51 PM
1/* 
2Use a std::map
3 */
4class ExamTracker {
5private:
6    vector<pair<int, long long>> scores;
7public:
8    ExamTracker() {
9        scores.push_back({-1, 0});
10    }
11    
12    void record(int time, int score) {
13        long long latestScore = scores.empty() ? 0 : scores.back().second;
14        scores.push_back({time, latestScore + score});
15    }
16    
17    long long totalScore(int startTime, int endTime) {
18        auto itStart = prev(lower_bound(scores.begin(), scores.end(), startTime, 
19            [](const pair<int, long long> &score, int target){
20                return score.first < target;
21            }
22        ));
23
24        auto itEnd = prev(upper_bound(scores.begin(), scores.end(), endTime, 
25            [](int target, const pair<int, long long> &score){
26                return score.first > target;
27            }
28        ));
29
30        // cout << distance(scores.begin(), itStart) << " " << distance(scores.begin(), itEnd) << endl;
31        // cout << (itEnd->second - itStart->second) << endl;
32
33        return itEnd->second - itStart->second;
34    }
35};
36
37/**
38 * Your ExamTracker object will be instantiated and called as such:
39 * ExamTracker* obj = new ExamTracker();
40 * obj->record(time,score);
41 * long long param_2 = obj->totalScore(startTime,endTime);
42 */