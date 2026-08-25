// Last updated: 8/25/2026, 9:13:19 PM
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
stack<TreeNode*> stleft;
stack<TreeNode*> stright;


void pushAllLeft(TreeNode* root){
    if(root==nullptr) return;
    while(root!=nullptr){
        stleft.push(root);
        root = root->left;
    }
}

void pushAllRight(TreeNode* root){
    if(root==nullptr) return;
    while(root!=nullptr){
        stright.push(root);
        root = root->right;
    }
}

int next() {
        TreeNode* curr = stleft.top();
        stleft.pop();

        // if curr has right child
        if(curr->right) pushAllLeft(curr->right);
        return curr->val;
    }

int before() {
        TreeNode* curr = stright.top();
        stright.pop();

        // if curr has left child
        if(curr->left) pushAllRight(curr->left);
        return curr->val;
    }


public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        pushAllLeft(root);
        pushAllRight(root);

      int l = next();
      int r = before();

        while(l < r){
           
            if(l + r ==k) return true;
            else if(l + r < k){
                l=next();
            }
            else r = before();
        }
        return false;

        
    }
};