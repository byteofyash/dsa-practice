// Last updated: 7/7/2026, 2:41:53 AM
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
    if(root==NULL) return;
    traverser(root->left, result);
        traverser(root->right, result);
        result.push_back(root->val);


}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverser(root, result);
        return result;
        
    }
};