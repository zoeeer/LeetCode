#include <vector>
#include<cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        vector<ListNode *> plist;
        for (ListNode *p = head; p != NULL; p = p->next)
            plist.push_back(p);
        int n = plist.size();
        int i, j;
        for (i = 0, j = n-1; i < j; ++i, --j) {
            plist[j]->next = plist[i]->next;
            plist[i]->next = plist[j];
        }
        if (i > 0)
            plist[i]->next = NULL;
    }
};
