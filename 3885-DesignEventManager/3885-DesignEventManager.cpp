// Last updated: 4/10/2026, 3:29:47 PM
1/* 
2
3eventId -> Priority
4
5Priority -> set<Eventid> 
6 */
7using EventId = int;
8using Priority = int;
9
10class EventManager {
11public:
12    EventManager(vector<vector<int>>& events) {
13        for (const vector<int> &event : events) {
14            EventId eventId = event[0];
15            Priority priority = event[1];
16
17            eventMap[eventId] = priority;
18            priorityMap[priority].insert(eventId);
19        }
20    }
21    
22    void updatePriority(int eventId, int newPriority) {
23        Priority oldPriority = eventMap[eventId];
24        eventMap[eventId] = newPriority;
25
26        priorityMap[oldPriority].erase(eventId);
27        if (priorityMap[oldPriority].empty()) {
28            priorityMap.erase(oldPriority);
29        }
30        priorityMap[newPriority].insert(eventId);
31    }
32    
33    int pollHighest() {
34        if (priorityMap.empty()) {
35            return -1;
36        }
37        cout << priorityMap.size() << endl;
38
39        int res = *prev(priorityMap.end())->second.begin();
40        prev(priorityMap.end())->second.erase(res);
41
42        eventMap.erase(res);
43
44        if (prev(priorityMap.end())->second.empty()) {
45            priorityMap.erase(prev(priorityMap.end()));
46        }
47
48        return res;
49    }
50
51private:
52    unordered_map<EventId, Priority> eventMap;
53    map<Priority, set<EventId>> priorityMap;
54};
55
56/**
57 * Your EventManager object will be instantiated and called as such:
58 * EventManager* obj = new EventManager(events);
59 * obj->updatePriority(eventId,newPriority);
60 * int param_2 = obj->pollHighest();
61 */