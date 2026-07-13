// Last updated: 7/13/2026, 11:31:55 PM
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
bool check(TreeNode* root1, TreeNode* root2){
    if(root1==nullptr && root2==nullptr) return true;
    else if (root1==nullptr && root2!=nullptr || root2==nullptr && root1!=nullptr) return false;
    else if(root1->val != root2->val) return false;

    bool left=  check(root1->left, root2->left);
    bool right =  check(root1->right, root2->right);
    return (left && right);

}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};