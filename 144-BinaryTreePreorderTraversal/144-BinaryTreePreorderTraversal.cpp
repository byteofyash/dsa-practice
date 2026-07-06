// Last updated: 7/7/2026, 2:41:56 AM
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

    void traverser(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;
        result.push_back(root->val);
        traverser(root->left, result);
        traverser(root->right, result);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        traverser(root, pre);
        return pre;
    }
};