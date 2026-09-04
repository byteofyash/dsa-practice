// Last updated: 9/4/2026, 4:59:38 PM
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
TreeNode* insert(TreeNode* root, int val){
    if (root == nullptr){
        return new TreeNode(val);
    }
    if(val > root->val ){
        //go into right subtree
       root->right = insert(root->right, val);
    }
    else{
        // go to left subtree
        root->left = insert(root->left, val);
    }
    return root;
}
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
            return insert(root,val);
    }
};