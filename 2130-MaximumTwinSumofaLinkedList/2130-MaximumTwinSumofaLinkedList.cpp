// Last updated: 7/13/2025, 6:43:39 PM
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
    int pairSum(ListNode* head) {
        int res = 0;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        ListNode* tmp = nullptr;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;

            tmp = slow;
            slow = slow->next;
            tmp->next = prev;
            prev = tmp;
        }
        ListNode* nextHalf = slow->next;
        ListNode* prevHalf = slow;
        slow->next = prev;
        while(prevHalf && nextHalf){
            res = max(res, prevHalf->val+nextHalf->val);
            prevHalf = prevHalf->next;
            nextHalf = nextHalf->next;
        }
        return res;
    }
};