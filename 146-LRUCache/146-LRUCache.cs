// Last updated: 3/4/2026, 1:34:32 AM
1/* 
2Just do it with events.
3 */
4public class Solution {
5    public class Event {
6        public int timestamp;
7        public bool end;
8        public Event(int t, bool e) { timestamp = t; end = e; }
9    }
10    
11    public int[][] Merge(int[][] intervals) {
12        List<Event> events = new List<Event>();
13        foreach (int[] interval in intervals) {
14            events.Add(new Event(interval[0], false));
15            events.Add(new Event(interval[1], true));
16        }
17        events.Sort((a, b) => {
18            int result = a.timestamp.CompareTo(b.timestamp);
19
20            if (result == 0) {
21                return a.end.CompareTo(b.end);
22            }
23
24            return result;
25        });
26
27        List<int[]> merged = new List<int[]>();
28
29        int currOpen = 0;
30        int prevOpen = 0;
31        foreach (Event e in events) {
32            if (currOpen == 0) {
33                prevOpen = e.timestamp;
34            }
35            if (!e.end) {
36                currOpen++;
37            } else {
38                currOpen--;
39            }
40            if (currOpen == 0) {
41                merged.Add(new int[] { prevOpen, e.timestamp });
42            }
43        }
44
45        return merged.ToArray();
46    }
47}