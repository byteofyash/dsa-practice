// Last updated: 7/7/2026, 2:40:57 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void traverser(TreeNode* root, int& count){
        if(root==NULL) return;
        count++;
        traverser(root->left, count);
        traverser(root->right, count);
    }
public:

    int countNodes(TreeNode* root) {
        int count = 0 ;
        traverser(root, count);
        return count;
        
    }
};