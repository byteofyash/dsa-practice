// Last updated: 7/14/2026, 3:43:16 AM
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
bool check(TreeNode* a, TreeNode* b){
    if(a==nullptr && b ==nullptr) return true;
    if((a==nullptr && b!=nullptr) ||( b==nullptr && a!=nullptr)) return false;
    if(a->val != b->val) return false;

    bool outer = check(a->left, b->right);
    bool inner = check(a->right, b->left);
    return outer && inner;
}
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};