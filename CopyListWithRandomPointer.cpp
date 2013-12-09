/*** Copy List with Random Pointer ***

A linked list is given such that each node contains an additional 
random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode * copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode *p = head;
        // duplicate nodes and insert into the origin list
        while (p != NULL) {
            RandomListNode *x = new RandomListNode(p->label);
            x->next = p->next;
            p->next = x;
            p = x->next;
        }
        // set random pointers
        for (p = head; p != NULL; p = p->next->next) {
            if (p->random != NULL)
                p->next->random = p->random->next;
        }
        // seperate two lists
        RandomListNode *newlist = head->next;
        RandomListNode *p2 = newlist;
        head->next = p2->next;
        for (p = head->next; p != NULL; ) {
            p2->next = p->next;
            p2 = p2->next;
            p->next = p2->next;
            p = p->next;
        }
        return newlist;
    }
};
