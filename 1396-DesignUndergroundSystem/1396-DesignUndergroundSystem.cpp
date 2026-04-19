// Last updated: 4/19/2026, 3:47:41 PM
1/* 
2unordered_map<int customerId, {int checkinTime, string stationName}> checkins;
3
4unordered_map<string, unordered_map<string, vector<int>>> journeys;
5 */
6class UndergroundSystem {
7private:
8    struct CheckinInfo {
9        string stationName;
10        int checkinTime;
11    };
12
13    unordered_map<int, CheckinInfo> checkins;
14
15    unordered_map<string, unordered_map<string, vector<int>>> journeys;
16public:
17    UndergroundSystem() {
18        
19    }
20    
21    void checkIn(int id, string stationName, int t) {
22        checkins[id] = CheckinInfo{stationName, t};
23    }
24    
25    void checkOut(int id, string stationName, int t) {
26        CheckinInfo info = checkins[id];
27        checkins.erase(id);
28
29        journeys[info.stationName][stationName].push_back(t - info.checkinTime);
30    }
31    
32    double getAverageTime(string startStation, string endStation) {
33        double res = 0;
34
35        for (int t : journeys[startStation][endStation]) {
36            res += t;
37        }
38
39        res /= journeys[startStation][endStation].size();
40
41        return res;
42    }
43};
44
45/**
46 * Your UndergroundSystem object will be instantiated and called as such:
47 * UndergroundSystem* obj = new UndergroundSystem();
48 * obj->checkIn(id,stationName,t);
49 * obj->checkOut(id,stationName,t);
50 * double param_3 = obj->getAverageTime(startStation,endStation);
51 */