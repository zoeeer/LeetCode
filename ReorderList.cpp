/*** Reorder List ***

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/
#include <vector>
#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *p1, *p2;
        p1 = p2 = head;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p1 == p2 || p1->next == NULL)
            return;

        p2 = ReverseList(p1->next);
        p1->next = NULL;
        p1 = head;

        // MergeList(p1, p2), assuming p1 is not shorter than p2
        while (p1 && p2) {
            ListNode *p = p1->next;
            p1->next = p2;
            p1 = p;
            p = p2->next;
            p2->next = p1;
            p2 = p;
        }

    }

    ListNode* ReverseList(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *p = head->next;
        head->next = NULL;

        while (p) {
            ListNode *p2 = head;
            head = p;
            p = p->next;
            head->next = p2;
        }
        return head;
    }

};
