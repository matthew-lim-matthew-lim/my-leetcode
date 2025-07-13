// Last updated: 7/13/2025, 10:26:43 PM
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;           // min-heap on val
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& v) {
        using Node = ListNode*;
        priority_queue<Node, vector<Node>, cmp> pq;

        /* push only the head of each non-empty list */
        for (Node head : v)
            if (head) pq.push(head);

        if (pq.empty()) return nullptr;       // every list was empty

        Node head = pq.top();                 // first (smallest) node
        Node tail = head;

        while (!pq.empty()) {
            tail = pq.top(); pq.pop();        // take smallest
            if (tail->next) pq.push(tail->next); // push successor
            if (!pq.empty()) tail->next = pq.top(); // link to new smallest
        }
        tail->next = nullptr;                 // terminate
        return head;
    }
};
