// Last updated: 7/13/2025, 6:38:26 PM
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
        stack<int> stk;

        ListNode* curr = head;
        int llSize = 0;

        while (curr != nullptr) {
            stk.push(curr->val);
            curr = curr->next;
            llSize++;
        }

        int maxRes = 0;

        curr = head;
        for (int i = 0; i < llSize / 2; i++) {
            maxRes = max(maxRes, curr->val + stk.top());
            stk.pop();

            curr = curr->next;
        }

        return maxRes;
    }
};