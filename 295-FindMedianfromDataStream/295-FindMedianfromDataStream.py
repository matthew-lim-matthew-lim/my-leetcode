# Last updated: 3/15/2026, 6:17:33 PM
1class MedianFinder:
2    smaller = []
3    bigger = []
4
5    def __init__(self):
6        self.smaller = []
7        self.bigger = []
8
9    def addNum(self, num: int) -> None:
10        heapq.heappush(self.smaller, -num)
11
12    def findMedian(self) -> float:
13        while not (len(self.smaller) == len(self.bigger) + 1 or len(self.smaller) == len(self.bigger)):
14            top_smaller = self.smaller[0]
15            heapq.heappush(self.bigger, -top_smaller)
16            heapq.heappop(self.smaller)
17
18        while self.smaller and self.bigger and -self.smaller[0] > self.bigger[0]:
19            top_smaller = self.smaller[0]
20            top_bigger = self.bigger[0]
21            heapq.heappop(self.smaller)
22            heapq.heappop(self.bigger)
23            heapq.heappush(self.bigger, -top_smaller)
24            heapq.heappush(self.smaller, -top_bigger)
25        
26        # print("finding median")
27        # print(self.smaller)
28        # print(self.bigger)
29        if len(self.smaller) == len(self.bigger) + 1:
30            return -self.smaller[0]
31        
32        return (-self.smaller[0] + self.bigger[0]) / 2
33
34
35# Your MedianFinder object will be instantiated and called as such:
36# obj = MedianFinder()
37# obj.addNum(num)
38# param_2 = obj.findMedian()