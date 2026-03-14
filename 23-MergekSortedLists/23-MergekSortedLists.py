# Last updated: 3/14/2026, 4:53:25 PM
1""" 
2Keep track of the index of the linked list with the lowest head value.
3Each turn, use the linked list with that lowest head.
4"""
5
6# Definition for singly-linked list.
7# class ListNode:
8#     def __init__(self, val=0, next=None):
9#         self.val = val
10#         self.next = next
11class Solution:
12    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
13        head: ListNode = None
14        tail: ListNode = None
15
16        while lists:
17            # print(lists)
18            lowest_index: int = -1
19            for i in range(len(lists)):
20                if lists[i] and (lowest_index == -1 or lists[i].val < lists[lowest_index].val):
21                    lowest_index = i
22            
23            # If all the lists are empty
24            if lowest_index == -1:
25                return head
26
27            if not tail:
28                tail = lists[lowest_index]
29                lists[lowest_index] = lists[lowest_index].next
30                tail.next = None
31                head = tail
32            else:
33                tail.next = lists[lowest_index]
34                lists[lowest_index] = lists[lowest_index].next
35                tail = tail.next
36                tail.next = None
37
38            # print(f"lists length: {len(lists)}")
39            if lists[lowest_index] == None:
40                del lists[lowest_index]
41        
42        return head
43
44
45            
46            
47
48
49            
50            
51            