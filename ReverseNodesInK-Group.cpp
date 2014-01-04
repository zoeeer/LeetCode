/*** Reverse Nodes in k-Group ***

Given a linked list, reverse the nodes of a linked list k at a time and 
return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the 
end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/
#include "list.h"

class Solution {
    ListNode* ReverseList(ListNode *head, ListNode *tail) {
        if (head == tail)
            return head;
        ListNode *p = head->next;
        head->next = tail;

        while (p != tail) {
            ListNode *p2 = head;
            head = p;
            p = p->next;
            head->next = p2;
        }
        return head;
    }
    
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1 || head == NULL)
            return head;

        ListNode *head0 = new ListNode(0);
        head0->next = head;

        int i = 0;
        ListNode *p = head, *pre = head0;
        while (p) {
            if (++i == k) {
                ListNode *h = pre->next;
                pre->next = ReverseList(h, p->next);
                i = 0;
                pre = h;
                p = pre->next;
            }
            else
                p = p->next;
        }
        head = head0->next;
        delete head0;
        return head;
    }
};
