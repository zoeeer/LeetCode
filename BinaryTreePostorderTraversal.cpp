/*** Binary Tree Preorder Traversal ***

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include <vector>
#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        vector<TreeNode *> stack;
        vector<bool> visit;
        if (root != NULL) {
            stack.push_back(root);
            visit.push_back(false);
        }
        while (!stack.empty()) {
            TreeNode *p = stack.back();
            if (visit.back() || (p->left == NULL && p->right == NULL)) {
                stack.pop_back();
                visit.pop_back();
                ans.push_back(p->val);
                continue;
            }
            visit.back() = true;
            if (p->right) {
                stack.push_back(p->right);
                visit.push_back(false);
            }
            if (p->left) {
                stack.push_back(p->left);
                visit.push_back(false);
            }
        }
        return ans;
    }
};
