// Last updated: 7/7/2026, 2:40:48 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return root;

        int curN = root->val;
        if (curN < p->val && curN < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (curN >p->val && curN > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};