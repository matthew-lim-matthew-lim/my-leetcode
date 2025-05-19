// Last updated: 5/19/2025, 11:18:23 PM
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
/* 
Get the address of the first node. 
Travel down k nodes. 
If it doesn't end, reverse them one-by-one. 



oldNext = curr->next;
curr->next = end;
curr = end->next;

do this k times
{
curr = oldNext;
oldNext = curr->next;
curr->next = prev;
prev = curr;
}

 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* oldEnd = head;
        ListNode* curr = head;
        ListNode* end = head;
        for (int i = 0; i < k-1 && end != nullptr; i++) {
            end = end->next;
        }
        if (end == nullptr) {
            return head;
        }
        head = end;

        // So far so good
        // Reverse first k manually.

        ListNode* oldNext = curr->next;
        ListNode* prev = end->next;
        for (int i = 0; i < k; i++) {
            oldNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = oldNext;
        }

        oldEnd->next = reverseKGroup(oldEnd->next, k);

        return head;
    }
};