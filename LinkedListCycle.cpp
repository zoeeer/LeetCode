/*** Linked List Cycle ***

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

*/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1, *p2;
        p1 = p2 = head;
        while (p2 != NULL && p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                return true;
        }
        return false;
    }
};
