/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = NULL;
        while (l1 != NULL || l2 != NULL) {
            ListNode* n = new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val : 0));
            if (tail) 
                tail->next = n;
            if (!head) 
                head = n;
            tail = n;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        
        for (ListNode *prev = head, *it = prev->next; prev != tail; ) {
            if (prev->val >= 10) {
                prev->val -= 10; 
                it->val += 1;
            }
            prev = it; it = it->next;
        }
        
        if (tail->val >= 10) {
            tail->val -= 10;
            tail->next = new ListNode(1);
        }
        
        return head;
    }  
};
