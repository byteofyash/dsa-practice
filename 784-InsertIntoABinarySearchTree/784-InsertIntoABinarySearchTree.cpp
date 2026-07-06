// Last updated: 7/7/2026, 2:39:42 AM
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // empty tree check
        if (root == NULL)
           return root = new TreeNode(val);
        TreeNode* currentNode = root;
        while (true) {
            if (currentNode->val < val) {
                if (currentNode->right != NULL)
                    currentNode = currentNode->right;
                else {
                    currentNode->right = new TreeNode(val);
                    break;
                }

            } else {
                if (currentNode->left != NULL)
                    currentNode = currentNode->left;
                else {
                    currentNode->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};