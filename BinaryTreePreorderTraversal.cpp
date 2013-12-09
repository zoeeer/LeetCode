/*** Binary Tree Preorder Traversal ***

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

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
        if (root != NULL)
            stack.push_back(root);
        while (!stack.empty()) {
            TreeNode *p = stack.back();
            stack.pop_back();
            if (p->right)
                stack.push_back(p->right);
            if (p->left)
                stack.push_back(p->left);
            ans.push_back(p->val);
        }
        return ans;
    }
};
