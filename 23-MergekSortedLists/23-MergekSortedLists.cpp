// Last updated: 7/13/2025, 10:11:41 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        
        int n = lists.size();

        // { value, index of lists }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            if (lists[i] != nullptr) {
                pq.push({ lists[i]->val, i });
            }
        }        

        ListNode* prevNode; 
        ListNode* currNode;

        while (!pq.empty()) {
            int listIndex = pq.top().second;
            pq.pop();

            currNode = lists[listIndex];

            if (res == nullptr) {
                res = currNode;
            } else {
                prevNode->next = currNode;
            }

            prevNode = currNode;

            lists[listIndex] = lists[listIndex]->next;

            if (lists[listIndex] != nullptr) {
                pq.push({ lists[listIndex]->val, listIndex });
            }
        }

        return res;
    }
};