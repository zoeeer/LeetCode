/*** Swap Nodes in Pairs ***

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the 
values in the list, only nodes itself can be changed.

*/
#include "list.h" // Definition for singly-linked list -- struct ListNode

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *head0 = new ListNode(0);
        head0->next = head;

        ListNode *p = head, *pre = head0;
        while (p && p->next) {
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = p;
            pre = p;
            p = p->next;
        }
        head = head0->next;
        delete head0;
        return head;
    }
};
