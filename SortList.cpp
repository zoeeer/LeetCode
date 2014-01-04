/*
  Sort a linked list in O(n log n) time using constant space complexity.
*/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* mergeSortList(ListNode *head) {
        if (head && head->next) {
            ListNode *p1 = head, *p2 = head->next;
            while (p2 && p2->next) {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            p2 = p1->next;
            p1->next = NULL;
            head = mergeSortList(head);
            p2 = mergeSortList(p2);
            return head = mergeList(head, p2);
        }
        return head;
    }

    ListNode* mergeList(ListNode *L1, ListNode *L2) {
        ListNode *head0 = new ListNode(0);
        ListNode *p = head0;
        while (L1 && L2) {
            if (L1->val <= L2->val) {
                p->next = L1;
                L1 = L1->next;
            }
            else {
                p->next = L2;
                L2 = L2->next;
            }
            p = p->next;
        }
        p->next = L1 ? L1 : L2;
        return head0->next;
    }

public:
    ListNode *sortList(ListNode *head) {
        return head = mergeSortList(head);
    }
};
