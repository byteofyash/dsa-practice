// Last updated: 8/25/2026, 9:15:55 PM
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
    TreeNode* first = nullptr;

    TreeNode* prev = nullptr;
    TreeNode* middle = nullptr;

    TreeNode* last = nullptr;

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);

    if(prev!=nullptr && prev->val > root->val){
        if(first==nullptr) {first  = prev;middle = root;}
        else last  = root;
    }
    prev  = root;
    inorder(root->right);


}
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
        else return;
        
    }
};