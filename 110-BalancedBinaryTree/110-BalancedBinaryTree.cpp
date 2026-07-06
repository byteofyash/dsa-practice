// Last updated: 7/7/2026, 2:42:23 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int dfsHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        TreeNode* node = root;

        int l = dfsHeight(node->left);
        int r = dfsHeight(node->right);
        
        if(l==-1 || r==-1) return -1;

        if (abs(l - r) > 1)
            return -1;

        return 1 + max(l, r);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (dfsHeight(root) != -1)
            return true;
        else
            return false;
    }
};