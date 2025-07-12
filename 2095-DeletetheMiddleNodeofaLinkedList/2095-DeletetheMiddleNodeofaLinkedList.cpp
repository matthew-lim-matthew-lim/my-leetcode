// Last updated: 7/12/2025, 11:19:48 PM
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
One pointer advances at 2x the rate.
*/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* ptr1Prev = head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        while (ptr2->next != nullptr) {
            ptr2 = ptr2->next;
            if (ptr2->next != nullptr) {
                ptr2 = ptr2->next;
            }

            ptr1Prev = ptr1;

            ptr1 = ptr1->next;
        }

        if (ptr1 == head) {
            head = nullptr;
        } else {
            ptr1Prev->next = ptr1Prev->next->next;
        }

        return head;
    }
};