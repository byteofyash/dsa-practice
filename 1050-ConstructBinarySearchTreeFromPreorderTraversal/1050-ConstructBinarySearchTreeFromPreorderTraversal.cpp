// Last updated: 7/15/2026, 6:18:47 PM
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
    int i =0;
    long long low = INT_MIN;
    long long high = INT_MAX;
TreeNode* build(long long low, long long high,vector<int>& preorder){
    if(i==preorder.size()|| preorder[i]<low || preorder[i]>high) return nullptr;
    TreeNode* node = new TreeNode(preorder[i]);
    i++;
    node->left = build(low, node->val, preorder);
    node->right = build(node->val, high, preorder);
    return node;




}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return build(low, high, preorder);
        
    }
};