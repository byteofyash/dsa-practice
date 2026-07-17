// Last updated: 7/17/2026, 6:09:14 PM
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

public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* leftRoot = curr->left;
                TreeNode* rightMost = leftRoot;

                while (rightMost->right) {
                    rightMost = rightMost->right;
                }
                rightMost->right = curr->right;
                curr->right = leftRoot;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};