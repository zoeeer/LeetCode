#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)
            return head;

        ListNode *pre = new ListNode(0);
        pre->next = head;
        head = pre;

        pre = head->next;
        for (ListNode *p = pre->next; p; p = pre->next) {
            int key = p->val;
            ListNode *p1 = head;
            while (p1->next->val < key)
                p1 = p1->next;
            if (p1->next != p) { // insert node
                pre->next = p->next;
                p->next = p1->next;
                p1->next = p;
            }
            else
                pre = p;
        }

        pre = head; head = head->next;
        delete pre;
        return head;
    }
};
