// Last updated: 7/7/2026, 2:42:40 AM
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
void traverser(TreeNode* root, vector<int>& result){
    if(root==NULL) return ;
    traverser(root->left,result);
    result.push_back(root->val);
    traverser(root->right,result);
}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverser(root, result);
        return result;
        
    }
};