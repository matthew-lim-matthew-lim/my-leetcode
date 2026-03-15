# Last updated: 3/15/2026, 12:19:25 PM
1""" 
2Just use a heap.
3
4Use a heap to gatekeep using the servers.
5
6When a new request is added, pop the heap entries into an ordered list.
7
8Get the next largest item in the ordered list index bigger than (i % k).
9If there is none, then just use the next largest item in the ordered list
10bigger than 0.
11"""
12class Solution:
13    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
14        # Next free time, Current load count, Current tuple index
15        data: list[tuple[int, int, int]] = [(0, 0, i) for i in range(k)]
16        # Next free time, Current load count, Current tuple index
17        active_data: SortedDict[str, tuple[int, int, int]] = SortedDict()
18
19        for index, time in enumerate(arrival):
20            while data and data[0][0] <= time:
21                new_free_time, new_load_count, new_tuple_index = data[0]
22                active_data[new_tuple_index] = (new_free_time, new_load_count, new_tuple_index)
23                heapq.heappop(data)            
24
25            if not active_data:
26                # Drop this packet
27                continue
28
29            idx = active_data.bisect_left(index % k)
30            if idx < len(active_data):
31                key = active_data.iloc[idx]
32            else:
33                key, val = active_data.peekitem(0)
34
35            free_time, load_count, tuple_index = active_data[key]
36            heapq.heappush(
37                data,
38                (arrival[index] + load[index], load_count + 1, tuple_index)
39            )
40            del active_data[key]
41
42            # print(key)
43
44
45        res_dict: dict[int, list[int]] = defaultdict(list)
46        for free_time, load_count, tuple_index in active_data.values():
47            res_dict[load_count].append(tuple_index)
48
49        while data:
50            next_free_time, load_count, tuple_index = heapq.heappop(data)
51            res_dict[load_count].append(tuple_index)
52
53        # print(res_dict)
54
55        return res_dict[max(res_dict)]